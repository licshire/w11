-- $Id: nexys2_fusp_cuff_dummy.vhd 509 2013-04-21 20:46:20Z mueller $
--
-- Copyright 2013- by Walter F.J. Mueller <W.F.J.Mueller@gsi.de>
--
-- This program is free software; you may redistribute and/or modify it under
-- the terms of the GNU General Public License as published by the Free
-- Software Foundation, either version 2, or at your option any later version.
--
-- This program is distributed in the hope that it will be useful, but
-- WITHOUT ANY WARRANTY, without even the implied warranty of MERCHANTABILITY
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
-- for complete details.
-- 
------------------------------------------------------------------------------
-- Module Name:    nexys2_fusp_cuff_dummy - syn
-- Description:    nexys2 minimal target (base; serport loopback)
--
-- Dependencies:   -
-- To test:        tb_nexys2
-- Target Devices: generic
-- Tool versions:  13.3; ghdl 0.29
--
-- Revision History: 
-- Date         Rev Version  Comment
-- 2013-01-01   467   1.0    Initial version (derived nexys2_fusp_dummy)
------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

use work.slvtypes.all;
use work.nxcramlib.all;

entity nexys2_fusp_cuff_dummy is        -- NEXYS 2 dummy (+fusp+cuff; loopback)
                                        -- implements nexys2_fusp_cuff_aif
  port (
    I_CLK50 : in slbit;                 -- 50 MHz board clock
    I_RXD : in slbit;                   -- receive data (board view)
    O_TXD : out slbit;                  -- transmit data (board view)
    I_SWI : in slv8;                    -- n2 switches
    I_BTN : in slv4;                    -- n2 buttons
    O_LED : out slv8;                   -- n2 leds
    O_ANO_N : out slv4;                 -- 7 segment disp: anodes   (act.low)
    O_SEG_N : out slv8;                 -- 7 segment disp: segments (act.low)
    O_MEM_CE_N : out slbit;             -- cram: chip enable   (act.low)
    O_MEM_BE_N : out slv2;              -- cram: byte enables  (act.low)
    O_MEM_WE_N : out slbit;             -- cram: write enable  (act.low)
    O_MEM_OE_N : out slbit;             -- cram: output enable (act.low)
    O_MEM_ADV_N  : out slbit;           -- cram: address valid (act.low)
    O_MEM_CLK : out slbit;              -- cram: clock
    O_MEM_CRE : out slbit;              -- cram: command register enable
    I_MEM_WAIT : in slbit;              -- cram: mem wait
    O_MEM_ADDR  : out slv23;            -- cram: address lines
    IO_MEM_DATA : inout slv16;          -- cram: data lines
    O_FLA_CE_N : out slbit;             -- flash ce..          (act.low)
    O_FUSP_RTS_N : out slbit;           -- fusp: rs232 rts_n
    I_FUSP_CTS_N : in slbit;            -- fusp: rs232 cts_n
    I_FUSP_RXD : in slbit;              -- fusp: rs232 rx
    O_FUSP_TXD : out slbit;             -- fusp: rs232 tx
    I_FX2_IFCLK : in slbit;             -- fx2: interface clock
    O_FX2_FIFO : out slv2;              -- fx2: fifo address
    I_FX2_FLAG : in slv4;               -- fx2: fifo flags
    O_FX2_SLRD_N : out slbit;           -- fx2: read enable    (act.low)
    O_FX2_SLWR_N : out slbit;           -- fx2: write enable   (act.low)
    O_FX2_SLOE_N : out slbit;           -- fx2: output enable  (act.low)
    O_FX2_PKTEND_N : out slbit;         -- fx2: packet end     (act.low)
    IO_FX2_DATA : inout slv8            -- fx2: data lines
  );
end nexys2_fusp_cuff_dummy;

architecture syn of nexys2_fusp_cuff_dummy is
  
begin

  O_TXD    <= I_RXD;                    -- loop back
  O_FUSP_TXD   <= I_FUSP_RXD;
  O_FUSP_RTS_N <= I_FUSP_CTS_N;

  O_FX2_SLRD_N <= '1';                  -- keep fx2 iface quiet
  O_FX2_SLWR_N <= '1';
  O_FX2_SLOE_N <= '1';
  O_FX2_PKTEND_N <= '1';
  
  CRAM : nx_cram_dummy                  -- connect CRAM to protection dummy
    port map (
      O_MEM_CE_N  => O_MEM_CE_N,
      O_MEM_BE_N  => O_MEM_BE_N,
      O_MEM_WE_N  => O_MEM_WE_N,
      O_MEM_OE_N  => O_MEM_OE_N,
      O_MEM_ADV_N => O_MEM_ADV_N,
      O_MEM_CLK   => O_MEM_CLK,
      O_MEM_CRE   => O_MEM_CRE,
      I_MEM_WAIT  => I_MEM_WAIT,
      O_MEM_ADDR  => O_MEM_ADDR,
      IO_MEM_DATA => IO_MEM_DATA
    );
  
  O_FLA_CE_N  <= '1';                   -- keep Flash memory disabled
  
end syn;
