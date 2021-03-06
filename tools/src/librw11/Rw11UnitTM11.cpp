// $Id: Rw11UnitTM11.cpp 983 2018-01-02 20:35:59Z mueller $
//
// Copyright 2015-2017 by Walter F.J. Mueller <W.F.J.Mueller@gsi.de>
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
// 2017-04-07   868   1.0.1  Dump(): add detail arg
// 2015-05-17   683   1.0    Initial version
// ---------------------------------------------------------------------------

/*!
  \file
  \brief   Implemenation of Rw11UnitTM11.
*/

#include "boost/bind.hpp"

#include "librtools/RosFill.hpp"
#include "Rw11CntlTM11.hpp"

#include "Rw11UnitTM11.hpp"

using namespace std;

/*!
  \class Retro::Rw11UnitTM11
  \brief FIXME_docs
*/

// all method definitions in namespace Retro
namespace Retro {

//------------------------------------------+-----------------------------------
//! Constructor

Rw11UnitTM11::Rw11UnitTM11(Rw11CntlTM11* pcntl, size_t index)
  : Rw11UnitTapeBase<Rw11CntlTM11>(pcntl, index),
    fTmds(0)
{
  // setup disk geometry: only rk05 supported, no rk05f !
  fType    = "tu10";
  fEnabled = true;
}

//------------------------------------------+-----------------------------------
//! Destructor

Rw11UnitTM11::~Rw11UnitTM11()
{}

//------------------------------------------+-----------------------------------
//! FIXME_docs

void Rw11UnitTM11::Dump(std::ostream& os, int ind, const char* text,
                        int detail) const
{
  RosFill bl(ind);
  os << bl << (text?text:"--") << "Rw11UnitTM11 @ " << this << endl;
  os << bl << "  fTmds:           " << fTmds    << endl;

  Rw11UnitTapeBase<Rw11CntlTM11>::Dump(os, ind, " ^", detail);
  return;
}
  
} // end namespace Retro
