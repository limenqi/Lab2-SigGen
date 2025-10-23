module sinegen #(
    parameter INCR_WIDTH = 8,
              A_WIDTH = 8,
              D_WIDTH = 8  
)(
    input logic [INCR_WIDTH-1:0] incr,
    input logic rst,
    input logic en,
    input logic clk,
    output logic [D_WIDTH-1:0] dout
);

    logic [A_WIDTH-1:0] addr;

counter addrCounter (
    .incr(incr),
    .rst(rst),
    .en(en),
    .clk(clk),
    .count(addr)
);

rom sinerom (
    .clk(clk),
    .addr(addr),
    .dout(dout)
);

endmodule 
