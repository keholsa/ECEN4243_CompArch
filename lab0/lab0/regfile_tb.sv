//Jose Perez
//Keenan hosapple

module regfile_tb();

   integer handle3;
   integer desc3;

    //inputs
    reg clk; 
    reg we3;
    reg [4:0] ra1;
    reg [4:0] ra2; 
    reg [4:0] wa3;
    reg [31:0] wd3;

    //outputs 
    wire [31:0] rd1;
    wire [31:0] rd2; 

    //regfile() run module
    regfile mut(
        .clk(clk),
        .we3(we3), 
        .ra1(we3),
        .ra2(ra2),
        .wa3(wa3), 
        .wd3(wd3),
        .rd1(rd1),
        .rd2(rd2) );

    //program initial setting
    initial
    begin
        

        ra1 = 5'd0; //read address
        ra2 = 5'd0; // read address 2

        we3 = 1'b1; //write enable set to 1 

        //output
        wa3 = 5'd0; //write address 
        wd3 = 32'd0;//write data port 
        clk= 1'b0;
        forever #5 clk = ~clk;
    end


    //program update
      
    always @(posedge clk) begin
        // Randomize addresses
        ra1 = $urandom%32;
        ra2 = $urandom%32;
        wa3 = $urandom%32;

        // Randomize write data
        wd3 = $urandom;
    end
    /*
    initial
     begin
	// Gives output file name
	handle3 = $fopen("test.out");
	// Tells when to finish simulation
	#3500 $finish;		
     end

    always 
        begin
        desc3 = handle3;
        #5 $fdisplay(desc3, "%d %32'd0 || %32'd0", 
        we3, rd1, rd2);
        end  
    */ 
   

endmodule