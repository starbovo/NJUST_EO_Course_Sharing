# 第二章实例总结

## 2选1选择器

```verilog
module mux mux_2_to_1(
    input a,
    input b,
    input sel,
    output out
);
always@ (a or b or sel)
    begin
        if(sel==1'b0)
            out=a;
        else
            out=b;
    end
endmodule
```
## 模为40的计数器
```verilog
module counter_40(
    input clk,
    input ret,
    output[5:0] qout
);
reg [5:0] qout;
always@(posedge clk or negedge rst)
    begin
        if(~rst)
            qout<=6'd00;
        else
        begin
            if(qout==6'd39)
                qout<=6'd0;
            else
                qout<=qout+6'd1;
        end
    end
endmodule
```
## 3-8译码器
```verilog
module decode_3to8(
input [2:0] data_in,
output [7:0] data_out
);
always@(data_in)
    begin
        case(data_in)
            3'b000:data_out=8'b0000_0001;
            3'b001:data_out=8'b0000_0010;
            3'b010:data_out=8'b0000_0100;
            3'b011:data_out=8'b0000_1000;
            3'b100:data_out=8'b0001_0000;
            3'b101:data_out=8'b0010_0000;
            3'b110:data_out=8'b0100_0000;
            3'b111:data_out=8'b1000_0000;
        endcase
    end
endmodule
```
## 有优先级的选择器
```verilog
module choose(
input [3:0] data_in,	//输入信号
input [2:0] sel,		//选择开关
output data_out			//输出信号
);
always@(data_in or sel)
    begin
        casez(sel)			//使用casez进行译码
            3'b1??:data_out=data_in[2];//sel[2]为1时，优先选data_in[2]
            3'b001:data_out=data_in[1];
            3'b000:data_out=data_in[0];
            default:data_out=data_in[3];
        endcase
    end
endmodule
```
## 加减法选择器
```verilog
always@(dataa or batab or add_sub)
begin
	if(add_sub)
		out=dataa+datab;
	else
		out=dataa-datab;
end
```
## 十进制计数器
```verilog
reg[3:0] counter;
always@(posedge clk)
    begin
        if(counter==4'h9)
            counter<=4'h0;
        else
            counter<=counter+4'h1;
    end
```
## 一个简单的同步电路
```verilog
wire Din;
wire Temp1;
wire Temp2;
always@(posedge clk or negedge rst)
    begin
        if(~rst)
            Q<=1'b0;
        else
            Q<=Din;
    end
assign Din=temp1&&temp2;
assign Temp1=A||B;
assign Temp2=C?(A&&B):D;
```

## 20分频电路

```verilog
module divide20(
	inout reset,
    input clock,
    output div_clk
);
    reg div_clk;
    reg [3:0] div_cnt;
    always@(posedge clock or negedge reset)
        begin
            if(~reset)
            begin
                div_cnt<=4'h0;
                div_clk<=1'b0;
            end
            else
            begin
                if(div_cnt==4'h9)
                begin
                    div_cnt<=4'h0;
                    div_clk<=~div_clk;
                end
                else
                begin
                    div_cnt<=div_cnt+4'h1;
                    div_clk<=div_clk;
                end
            end
        end
endmodule
```

整理：电光20小赵

纯手打，根据自己的代码习惯修改了一些多余的begin和end对，input和output也都调整到端口声明里面了。
