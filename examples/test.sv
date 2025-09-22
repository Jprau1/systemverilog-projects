module test 
(
    input logic clk,
    input logic in_a, 
    input logic in_b, 
    output logic out
);

always_ff @(posedge clk) begin
    out <= in_a & in_b;
end

endmodule