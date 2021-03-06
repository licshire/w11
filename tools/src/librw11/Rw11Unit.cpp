// $Id: Rw11Unit.cpp 1049 2018-09-22 13:56:52Z mueller $
//
// Copyright 2013-2018 by Walter F.J. Mueller <W.F.J.Mueller@gsi.de>
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
// 2017-04-15   875   1.1.3  add IsAttached(), AttachUrl()
// 2017-04-07   868   1.1.2  Dump(): add detail arg
// 2015-05-13   680   1.1.1  add Enabled()
// 2013-05-03   515   1.1    use AttachDone(),DetachCleanup(),DetachDone()
// 2013-03-06   495   1.0    Initial version
// 2013-02-13   488   0.1    First draft
// ---------------------------------------------------------------------------

/*!
  \file
  \brief   Implemenation of Rw11Unit.
*/

#include "librtools/RosFill.hpp"

#include "Rw11Unit.hpp"
#include "Rw11Virt.hpp"

using namespace std;

/*!
  \class Retro::Rw11Unit
  \brief FIXME_docs
*/

// all method definitions in namespace Retro
namespace Retro {

//------------------------------------------+-----------------------------------
//! Constructor

Rw11Unit::Rw11Unit(Rw11Cntl* pcntl, size_t index)
  : fpCntlBase(pcntl),
    fIndex(index),
    fAttachOpts(),
    fStats()
{}

//------------------------------------------+-----------------------------------
//! Destructor

Rw11Unit::~Rw11Unit()
{}

//------------------------------------------+-----------------------------------
//! FIXME_docs

bool Rw11Unit::Enabled() const
{    
  return true;
}

//------------------------------------------+-----------------------------------
//! FIXME_docs

bool Rw11Unit::IsAttached() const
{
  return bool(VirtBase());
}

//------------------------------------------+-----------------------------------
//! FIXME_docs

const std::string&  Rw11Unit::AttachUrl() const
{
  if (VirtBase()) {
    return VirtBase()->Url().Url();
  }
  
  static const string strnil;
  return strnil;
}

//------------------------------------------+-----------------------------------
//! FIXME_docs

bool Rw11Unit::Attach(const std::string& /*url*/, RerrMsg& emsg)
{
  emsg.Init("Rw11Unit::Attach","attach not available for this device type");
  return false;
}

//------------------------------------------+-----------------------------------
//! FIXME_docs

void Rw11Unit::Detach()
{
  return;
}

//------------------------------------------+-----------------------------------
//! FIXME_docs

void Rw11Unit::Dump(std::ostream& os, int ind, const char* text,
                    int detail) const
{
  RosFill bl(ind);
  os << bl << (text?text:"--") << "Rw11Unit @ " << this << endl;

  os << bl << "  fIndex:          " << fIndex << endl;
  os << bl << "  fAttachOpts:     " << fAttachOpts << endl;
  fStats.Dump(os, ind+2, "fStats: ", detail-1);
  return;
}

//------------------------------------------+-----------------------------------
//! FIXME_docs

void Rw11Unit::AttachDone()
{}
  
//------------------------------------------+-----------------------------------
//! FIXME_docs

void Rw11Unit::DetachCleanup()
{}

//------------------------------------------+-----------------------------------
//! FIXME_docs

void Rw11Unit::DetachDone()
{}

} // end namespace Retro
