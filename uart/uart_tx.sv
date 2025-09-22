module uart_tx
	#(
		parameter int unsigned PAYLOAD_BITS = 8,
		parameter int unsigned STOP_BITS    = 2,
		parameter int unsigned BAUD_RATE    = 115_200,
		parameter int unsigned CLK_FREQ     = 8_000_000
	)
	(
		input		logic						clk,
		input		logic						tx_reset,	// active-high synchronous reset
		input		logic						tx_enable,	// 1-cycle strobe when idle
		input		logic	[PAYLOAD_BITS-1:0]	tx_data,
		output	logic						tx_busy,
		output	logic						tx_serial
	);

	localparam int unsigned CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;

	localparam FSM_IDLE		= 2'b00;
	localparam FSM_START	= 2'b01;
	localparam FSM_SEND		= 2'b10;
	localparam FSM_STOP		= 2'b11;

	logic [$clog2(CLKS_PER_BIT)-1:0]	cycle_counter;
	logic [$clog2(PAYLOAD_BITS)-1:0]	bit_index;
	logic [$clog2(STOP_BITS)-1:0]		stop_cnt;
	logic [PAYLOAD_BITS-1:0]			tx_data_buffer;
	logic [1:0]						fsm_state;

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
							fsm_state <= FSM_STOP;
						end
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
