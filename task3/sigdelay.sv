module sigdelay #(
    parameter A_WIDTH = 9,
              D_WIDTH = 8  
)(
    input  logic rst,
    input  logic wr,
    input  logic rd,
    input  logic clk,
    input  logic [A_WIDTH-1:0] offset,
    input  logic [D_WIDTH-1:0] mic_signal,
    output logic [D_WIDTH-1:0] delayed_signal
);

    logic [A_WIDTH-1:0] rd_addr;
    logic [A_WIDTH-1:0] wr_addr;
    assign wr_addr = rd_addr + offset;

counter addrCounter (
    .rst(rst),
    .clk(clk),
    .wr_addr(rd_addr)
);

ram RAM (
    .clk(clk),
    .rd(rd),
    .wr(wr),
    .wr_addr(wr_addr),
    .rd_addr(rd_addr),
    .din(mic_signal),
    .dout(delayed_signal)   
);

endmodule 
