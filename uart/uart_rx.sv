module uart_rx
    #(
    	parameter int unsigned PAYLOAD_BITS = 8,
		parameter int unsigned STOP_BITS    = 1,
		parameter int unsigned PARITY_EN    = 1,
		parameter int unsigned BAUD_RATE    = 115_200,
		parameter int unsigned CLK_FREQ     = 8_000_000
    )
    (
        input   logic                       clk;
        input	logic						rx_reset,
        input	logic						rx_enable,
        input   logic                       rx_serial,
        output  logic	[PAYLOAD_BITS-1:0]	rx_data,
        output  logic                       rx_valid
    );

    

endmodule