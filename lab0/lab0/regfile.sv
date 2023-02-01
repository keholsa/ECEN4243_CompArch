//jose Perez
//keennan hosapple

module regfile(
      input         clk, //clock
		input  	    we3, //write enable
		input  [4:0]   ra1, ra2, wa3, //read address 1, read address 2, write address 3 
		input  [31:0]  wd3, //write data 
		output  [31:0] rd1, rd2); //read data output 1, read data output 2 
   
   reg [31:0] 		    rf[31:0];// create a 32, 32 bit registers 
   
   // three ported register file
   // read two ports combinationally
   // write third port on rising edge of clock
   // register 0 hardwired to 0

   //set read ports
   assign rd1 = (ra1 == 0 ) ? 32'd0 : rf[ra1] ; //32 size of rd1
   assign rd2 = (ra2 == 0) ? 32'd0 : rf[ra2] ; // read data output port get data from rf{ra2} address
                                          

   always @(posedge clk) 
   begin
      if(we3 && wa3 != 5'd0 ) // if write is enabled and writing to register 0 has no effect 
      begin
         rf[wa3] <= wd3; // write data set 
      end
      
   end


   
   
endmodule // regfile
