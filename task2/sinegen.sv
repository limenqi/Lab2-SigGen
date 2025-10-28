module sinegen #(
    parameter OFFSET_WIDTH = 8,
              A_WIDTH = 8,
              D_WIDTH = 8  
)(
    input logic [OFFSET_WIDTH-1:0] offset,
    input logic rst,
    input logic en,
    input logic clk,
    output logic [D_WIDTH-1:0] dout1,
    output logic [D_WIDTH-1:0] dout2
);

    logic [A_WIDTH-1:0] addr1, addr2;

counter addrCounter (
    .rst(rst),
    .en(en),
    .clk(clk),
    .count(addr1)
);

assign addr2 = addr1 + offset;

rom sinerom (
    .clk(clk),
    .addr1(addr1), 
    .addr2(addr2),
    .dout1(dout1),
    .dout2(dout2)   
);

endmodule 
