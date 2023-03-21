set_property PACKAGE_PIN U12 [get_ports btn0]
set_property IOSTANDARD LVCMOS33 [get_ports btn0]

create_debug_core u_ila_0 ila
set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0]
set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0]
set_property C_DATA_DEPTH 1024 [get_debug_cores u_ila_0]
set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0]
set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
set_property port_width 1 [get_debug_ports u_ila_0/clk]
connect_debug_port u_ila_0/clk [get_nets [list design_1_i/processing_system7_0/inst/FCLK_CLK0]]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe0]
set_property port_width 32 [get_debug_ports u_ila_0/probe0]
connect_debug_port u_ila_0/probe0 [get_nets [list {design_1_i/top_0/inst/PC[0]} {design_1_i/top_0/inst/PC[1]} {design_1_i/top_0/inst/PC[2]} {design_1_i/top_0/inst/PC[3]} {design_1_i/top_0/inst/PC[4]} {design_1_i/top_0/inst/PC[5]} {design_1_i/top_0/inst/PC[6]} {design_1_i/top_0/inst/PC[7]} {design_1_i/top_0/inst/PC[8]} {design_1_i/top_0/inst/PC[9]} {design_1_i/top_0/inst/PC[10]} {design_1_i/top_0/inst/PC[11]} {design_1_i/top_0/inst/PC[12]} {design_1_i/top_0/inst/PC[13]} {design_1_i/top_0/inst/PC[14]} {design_1_i/top_0/inst/PC[15]} {design_1_i/top_0/inst/PC[16]} {design_1_i/top_0/inst/PC[17]} {design_1_i/top_0/inst/PC[18]} {design_1_i/top_0/inst/PC[19]} {design_1_i/top_0/inst/PC[20]} {design_1_i/top_0/inst/PC[21]} {design_1_i/top_0/inst/PC[22]} {design_1_i/top_0/inst/PC[23]} {design_1_i/top_0/inst/PC[24]} {design_1_i/top_0/inst/PC[25]} {design_1_i/top_0/inst/PC[26]} {design_1_i/top_0/inst/PC[27]} {design_1_i/top_0/inst/PC[28]} {design_1_i/top_0/inst/PC[29]} {design_1_i/top_0/inst/PC[30]} {design_1_i/top_0/inst/PC[31]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe1]
set_property port_width 32 [get_debug_ports u_ila_0/probe1]
connect_debug_port u_ila_0/probe1 [get_nets [list {design_1_i/top_0/inst/writeDataM[0]} {design_1_i/top_0/inst/writeDataM[1]} {design_1_i/top_0/inst/writeDataM[2]} {design_1_i/top_0/inst/writeDataM[3]} {design_1_i/top_0/inst/writeDataM[4]} {design_1_i/top_0/inst/writeDataM[5]} {design_1_i/top_0/inst/writeDataM[6]} {design_1_i/top_0/inst/writeDataM[7]} {design_1_i/top_0/inst/writeDataM[8]} {design_1_i/top_0/inst/writeDataM[9]} {design_1_i/top_0/inst/writeDataM[10]} {design_1_i/top_0/inst/writeDataM[11]} {design_1_i/top_0/inst/writeDataM[12]} {design_1_i/top_0/inst/writeDataM[13]} {design_1_i/top_0/inst/writeDataM[14]} {design_1_i/top_0/inst/writeDataM[15]} {design_1_i/top_0/inst/writeDataM[16]} {design_1_i/top_0/inst/writeDataM[17]} {design_1_i/top_0/inst/writeDataM[18]} {design_1_i/top_0/inst/writeDataM[19]} {design_1_i/top_0/inst/writeDataM[20]} {design_1_i/top_0/inst/writeDataM[21]} {design_1_i/top_0/inst/writeDataM[22]} {design_1_i/top_0/inst/writeDataM[23]} {design_1_i/top_0/inst/writeDataM[24]} {design_1_i/top_0/inst/writeDataM[25]} {design_1_i/top_0/inst/writeDataM[26]} {design_1_i/top_0/inst/writeDataM[27]} {design_1_i/top_0/inst/writeDataM[28]} {design_1_i/top_0/inst/writeDataM[29]} {design_1_i/top_0/inst/writeDataM[30]} {design_1_i/top_0/inst/writeDataM[31]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe2]
set_property port_width 32 [get_debug_ports u_ila_0/probe2]
connect_debug_port u_ila_0/probe2 [get_nets [list {design_1_i/top_0/inst/Instr[0]} {design_1_i/top_0/inst/Instr[1]} {design_1_i/top_0/inst/Instr[2]} {design_1_i/top_0/inst/Instr[3]} {design_1_i/top_0/inst/Instr[4]} {design_1_i/top_0/inst/Instr[5]} {design_1_i/top_0/inst/Instr[6]} {design_1_i/top_0/inst/Instr[7]} {design_1_i/top_0/inst/Instr[8]} {design_1_i/top_0/inst/Instr[9]} {design_1_i/top_0/inst/Instr[10]} {design_1_i/top_0/inst/Instr[11]} {design_1_i/top_0/inst/Instr[12]} {design_1_i/top_0/inst/Instr[13]} {design_1_i/top_0/inst/Instr[14]} {design_1_i/top_0/inst/Instr[15]} {design_1_i/top_0/inst/Instr[16]} {design_1_i/top_0/inst/Instr[17]} {design_1_i/top_0/inst/Instr[18]} {design_1_i/top_0/inst/Instr[19]} {design_1_i/top_0/inst/Instr[20]} {design_1_i/top_0/inst/Instr[21]} {design_1_i/top_0/inst/Instr[22]} {design_1_i/top_0/inst/Instr[23]} {design_1_i/top_0/inst/Instr[24]} {design_1_i/top_0/inst/Instr[25]} {design_1_i/top_0/inst/Instr[26]} {design_1_i/top_0/inst/Instr[27]} {design_1_i/top_0/inst/Instr[28]} {design_1_i/top_0/inst/Instr[29]} {design_1_i/top_0/inst/Instr[30]} {design_1_i/top_0/inst/Instr[31]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe3]
set_property port_width 32 [get_debug_ports u_ila_0/probe3]
connect_debug_port u_ila_0/probe3 [get_nets [list {design_1_i/top_0/inst/addressM[0]} {design_1_i/top_0/inst/addressM[1]} {design_1_i/top_0/inst/addressM[2]} {design_1_i/top_0/inst/addressM[3]} {design_1_i/top_0/inst/addressM[4]} {design_1_i/top_0/inst/addressM[5]} {design_1_i/top_0/inst/addressM[6]} {design_1_i/top_0/inst/addressM[7]} {design_1_i/top_0/inst/addressM[8]} {design_1_i/top_0/inst/addressM[9]} {design_1_i/top_0/inst/addressM[10]} {design_1_i/top_0/inst/addressM[11]} {design_1_i/top_0/inst/addressM[12]} {design_1_i/top_0/inst/addressM[13]} {design_1_i/top_0/inst/addressM[14]} {design_1_i/top_0/inst/addressM[15]} {design_1_i/top_0/inst/addressM[16]} {design_1_i/top_0/inst/addressM[17]} {design_1_i/top_0/inst/addressM[18]} {design_1_i/top_0/inst/addressM[19]} {design_1_i/top_0/inst/addressM[20]} {design_1_i/top_0/inst/addressM[21]} {design_1_i/top_0/inst/addressM[22]} {design_1_i/top_0/inst/addressM[23]} {design_1_i/top_0/inst/addressM[24]} {design_1_i/top_0/inst/addressM[25]} {design_1_i/top_0/inst/addressM[26]} {design_1_i/top_0/inst/addressM[27]} {design_1_i/top_0/inst/addressM[28]} {design_1_i/top_0/inst/addressM[29]} {design_1_i/top_0/inst/addressM[30]} {design_1_i/top_0/inst/addressM[31]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe4]
set_property port_width 32 [get_debug_ports u_ila_0/probe4]
connect_debug_port u_ila_0/probe4 [get_nets [list {design_1_i/top_0/inst/readDataM[0]} {design_1_i/top_0/inst/readDataM[1]} {design_1_i/top_0/inst/readDataM[2]} {design_1_i/top_0/inst/readDataM[3]} {design_1_i/top_0/inst/readDataM[4]} {design_1_i/top_0/inst/readDataM[5]} {design_1_i/top_0/inst/readDataM[6]} {design_1_i/top_0/inst/readDataM[7]} {design_1_i/top_0/inst/readDataM[8]} {design_1_i/top_0/inst/readDataM[9]} {design_1_i/top_0/inst/readDataM[10]} {design_1_i/top_0/inst/readDataM[11]} {design_1_i/top_0/inst/readDataM[12]} {design_1_i/top_0/inst/readDataM[13]} {design_1_i/top_0/inst/readDataM[14]} {design_1_i/top_0/inst/readDataM[15]} {design_1_i/top_0/inst/readDataM[16]} {design_1_i/top_0/inst/readDataM[17]} {design_1_i/top_0/inst/readDataM[18]} {design_1_i/top_0/inst/readDataM[19]} {design_1_i/top_0/inst/readDataM[20]} {design_1_i/top_0/inst/readDataM[21]} {design_1_i/top_0/inst/readDataM[22]} {design_1_i/top_0/inst/readDataM[23]} {design_1_i/top_0/inst/readDataM[24]} {design_1_i/top_0/inst/readDataM[25]} {design_1_i/top_0/inst/readDataM[26]} {design_1_i/top_0/inst/readDataM[27]} {design_1_i/top_0/inst/readDataM[28]} {design_1_i/top_0/inst/readDataM[29]} {design_1_i/top_0/inst/readDataM[30]} {design_1_i/top_0/inst/readDataM[31]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe5]
set_property port_width 1 [get_debug_ports u_ila_0/probe5]
connect_debug_port u_ila_0/probe5 [get_nets [list design_1_i/top_0/inst/reset]]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets u_ila_0_FCLK_CLK0]