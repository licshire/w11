// $Id: RlinkCrc16.hpp 983 2018-01-02 20:35:59Z mueller $
//
// Copyright 2014- by Walter F.J. Mueller <W.F.J.Mueller@gsi.de>
//
// This program is free software; you may redistribute and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY, without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for complete details.
// 
// Revision History: 
// Date         Rev Version  Comment
// 2014-11-08   602   1.0    Initial version
// ---------------------------------------------------------------------------


/*!
  \file
  \brief   Declaration of class \c RlinkCrc16.
*/

#ifndef included_Retro_RlinkCrc16
#define included_Retro_RlinkCrc16 1

#include <cstdint>
#include <vector>

namespace Retro {

  class RlinkCrc16 {
    public:
                    RlinkCrc16();
                   ~RlinkCrc16();

      void          Clear();
      void          AddData(uint8_t data);
      uint16_t      Crc() const;    

    protected: 

      uint16_t      fCrc;                   //!< current crc value
      static const uint16_t fCrc16Table[256];   // doxed in cpp
  };
  
} // end namespace Retro

#include "RlinkCrc16.ipp"

#endif
