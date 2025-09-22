module tb_test();

logic clk, a, b, out;

test myAdder(.clk(clk), .in_a(a), .in_b(b), .out(out));

initial clk = 0;
always #10 clk = ~clk;

initial begin
    a = 0;
    b = 0;
    $display ("a=%0d, b=%0d, out=%0d",a,b,out);
    #25 a = 1;
    $display ("a=%0d, b=%0d, out=%0d",a,b,out);
    #25 b = 1;
    $display ("a=%0d, b=%0d, out=%0d",a,b,out);
    #50;
    $display ("a=%0d, b=%0d, out=%0d",a,b,out);
    $finish;
end

endmodule