module stimulus ();

   logic  clock;
   logic  In;
   logic  reset_b;
   
   logic  Out;
   
   integer handle3;
   integer desc3;
   
   // Instantiate DUT
   FSM dut (Out, reset_b, clock, In);

   // Setup the clock to toggle every 1 time units 
   initial 
     begin	
	clock = 1'b1;
	forever #5 clock = ~clock;
     end

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
	#5 $fdisplay(desc3, "%b %b || %b", 
		     reset_b, In, Out);
     end   
   
   initial 
     begin      
	#0  reset_b = 1'b0;

	#12 reset_b = 1'b1;	//start of cycle. path 0210
	#0  In = 1'b0; // input 0 got to s2
	#20 In = 1'b1;//goes to state 1 
	#20 In = 1'b0;//goes to state 0

     #20 In = 1'b0;	//start of cycle. 0 path 0022102
	#20 In = 1'b0; //goes to state 2
	#20 In = 1'b1;//goes to state  2
	#20 In = 1'b1;//goes to state 1
	#20 In = 1'b0;//goes to state 0 
	#20 In = 1'b1;//goes to state 2



     end

endmodule // FSM_tb

