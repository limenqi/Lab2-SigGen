// note: counter controls the address being sent and received from the rom
module counter #(
    parameter OUTPUT_WIDTH = 8
)(
    input  logic rst,
    input  logic clk,
    output logic [OUTPUT_WIDTH-1:0] wr_addr
);

always_ff @(posedge clk) begin
    if (rst) wr_addr <= '0;
    else wr_addr <= wr_addr + 1;
end

endmodule
