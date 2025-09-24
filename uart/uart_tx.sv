module uart_tx
	#(
		parameter int unsigned PAYLOAD_BITS = 8,
		parameter int unsigned STOP_BITS    = 1,
		parameter int unsigned PARITY_EN    = 1,
		parameter int unsigned BAUD_RATE    = 115_200,
		parameter int unsigned CLK_FREQ     = 8_000_000
	)
	(
		input	logic						clk,
		input	logic						tx_reset,	// active-high synchronous reset
		input	logic						tx_enable,	// 1-cycle strobe when idle
		input	logic	[PAYLOAD_BITS-1:0]	tx_data,
		output	logic						tx_busy,
		output	logic						tx_serial
	);

	localparam int unsigned CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;

	localparam FSM_IDLE		= 3'h0;
	localparam FSM_START	= 3'h1;
	localparam FSM_SEND		= 3'h2;
	localparam FSM_PARITY	= 3'h3;
	localparam FSM_STOP		= 3'h4;

	logic [$clog2(CLKS_PER_BIT)-1:0]	cycle_counter;
	logic [$clog2(PAYLOAD_BITS)-1:0]	bit_index;
	logic [$clog2(STOP_BITS)-1:0]		stop_cnt;
	logic [PAYLOAD_BITS-1:0]			tx_data_buffer;
	logic [2:0]							fsm_state;

	always_ff @(posedge clk) begin
		if (tx_reset) begin
			fsm_state		<= FSM_IDLE;
			tx_serial		<= 1'b1;
			tx_busy			<= 1'b0;
			cycle_counter	<= 'b0;
			bit_index		<= 'b0;
			stop_cnt		<= 'b0;
			tx_data_buffer	<= 'b0;
		end
		else begin
			case (fsm_state)
				FSM_IDLE : begin
					tx_serial		<= 1'b1;
					tx_busy			<= 1'b0;
					cycle_counter	<= 'b0;
					bit_index		<= 'b0;
					stop_cnt		<= 'b0;

					if (tx_enable) begin
						tx_busy			<= 1'b1;
						tx_data_buffer	<= tx_data;
						fsm_state		<= FSM_START;
					end
					else begin
						fsm_state		<= FSM_IDLE;
					end
				end

				FSM_START : begin
					tx_serial <= 1'b0;

					if (cycle_counter < CLKS_PER_BIT-1) begin
						cycle_counter <= cycle_counter + 1;
					end
					else begin
						cycle_counter <= 'b0;
						fsm_state <= FSM_SEND;
					end
				end

				FSM_SEND : begin
					tx_serial <= tx_data_buffer[bit_index];

					if (cycle_counter < CLKS_PER_BIT-1) begin
						cycle_counter <= cycle_counter + 1;
					end
					else begin
						cycle_counter <= 'b0;

						if (bit_index < PAYLOAD_BITS-1) begin
							bit_index <= bit_index + 1;
						end
						else begin
							bit_index <= 'b0;
							if (PARITY_EN) begin
								fsm_state <= FSM_PARITY;
							end
							else begin
								fsm_state <= FSM_STOP;
							end
						end
					end
				end

				FSM_PARITY : begin
					tx_serial <= ^tx_data_buffer; // even parity

					if (cycle_counter < CLKS_PER_BIT-1) begin
						cycle_counter <= cycle_counter + 1;
					end
					else begin
						cycle_counter <= 'b0;
						fsm_state <= FSM_STOP;
					end
				end

				FSM_STOP : begin
					tx_serial <= 1'b1;

					if (cycle_counter < CLKS_PER_BIT-1) begin
						cycle_counter <= cycle_counter + 1;
					end
					else begin
						cycle_counter <= 'b0;

						if (stop_cnt < STOP_BITS-1) begin
							stop_cnt <= stop_cnt + 1;
						end
						else begin
							stop_cnt  <= 'b0;
							tx_busy   <= 1'b0;
							fsm_state <= FSM_IDLE;
						end
					end
				end

				default : begin
					fsm_state <= FSM_IDLE;
					tx_serial <= 1'b1;
					tx_busy   <= 1'b0;
				end
			endcase
		end
	end

endmodule
