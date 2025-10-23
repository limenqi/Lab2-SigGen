module counter #(
    parameter INPUT_WIDTH = 8,
              OUTPUT_WIDTH = 8
)(
    input logic [INPUT_WIDTH-1:0] incr,
    input logic rst,
    input logic en,
    input logic clk,
    output logic [OUTPUT_WIDTH-1:0] count
);

always_ff @(posedge clk) begin
    if (rst) count <= '0;
    else if (en) count <= count + incr;
end

endmodule
