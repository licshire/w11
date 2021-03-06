// $Id: RtclRw11VirtFactory.cpp 983 2018-01-02 20:35:59Z mueller $
//
// Copyright 2017- by Walter F.J. Mueller <W.F.J.Mueller@gsi.de>
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
// 2017-03-11   589   1.0    Initial version
// ---------------------------------------------------------------------------

/*!
  \file
  \brief   Implemenation of global function RtclRw11VirtFactory.
*/

#include "librw11/Rw11VirtDiskOver.hpp"

#include "RtclRw11VirtDiskOver.hpp"

#include "RtclRw11VirtFactory.hpp"

using namespace std;

// all method definitions in namespace Retro (avoid using in includes...)
namespace Retro {

//------------------------------------------+-----------------------------------
//! FIXME_docs

RtclRw11Virt* RtclRw11VirtFactory(Rw11Virt* pobj)
{
  // 'factory section', create concrete RtclRw11Virt objects
  
  Rw11VirtDiskOver* pdiskover = dynamic_cast<Rw11VirtDiskOver*>(pobj);
  if (pdiskover) {
    return new RtclRw11VirtDiskOver(pdiskover);
  }  

  return nullptr;
}

} // end namespace Retro
