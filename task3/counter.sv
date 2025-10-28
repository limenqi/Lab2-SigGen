// note: counter controls the address being sent and received from the rom
module counter #(
    parameter OUTPUT_WIDTH = 8
)(
    input  logic rst,
    input  logic clk,
    output logic [OUTPUT_WIDTH-1:0] rd_addr
);

always_ff @(posedge clk) begin
    if (rst) rd_addr <= '0;
    else rd_addr <= rd_addr + 1;
end

endmodule


