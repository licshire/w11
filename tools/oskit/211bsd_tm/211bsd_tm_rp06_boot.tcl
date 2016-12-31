# $Id: 211bsd_tm_rp06_boot.tcl 835 2016-12-31 10:00:14Z mueller $
#
# Setup file for creating a 211bsd RP06 system from a TM11 dist kit
#
# Usage:
#   
# console_starter -d DL0 &
# console_starter -d DL1 &
# create_disk --typ=rp06 --bad 211bsd_rp06.dsk
# ti_w11 -xxx @211bsd_tm_boot.tcl        ( -xxx depends on sim or fpga connect)
#

# setup w11 cpu
rutil::dohook "preinithook"
puts [rlw]

# setup tt,lp (211bsd uses parity -> use 7 bit mode)
rw11::setup_tt "cpu0" to7bit 1
rw11::setup_lp 

# mount disks
cpu0rpa0 set type rp06
cpu0rpa1 set type rp06

cpu0rpa0 att 211bsd_rp06.dsk

# mount tapes
cpu0tma0 att 211bsd_tm.tap?wpro

# and boot
rutil::dohook "preboothook"
cpu0 boot tma0
