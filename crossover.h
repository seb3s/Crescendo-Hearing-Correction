/*
 *  crossover.h
 *  CrescendoPlayThru
 *
 *  Created by David McClain on 10/18/07.
 *  Copyright 2007 Refined Audiometrics Laboratory. All rights reserved.
 *
 */

/* -----------------------------------------------------------------------------
 Copyright (c) 2016 Refined Audiometrics Laboratory, LLC
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 3. The names of the authors and contributors may not be used to endorse
 or promote products derived from this software without specific prior
 written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.
 ------------------------------------------------------------------------------- */
#ifndef __CROSSOVER_H__
#define __CROSSOVER_H__

#include "smart_ptr.h"
#include "TDelay.h"
#include "TFilter.h"

class TCrossOver
{
public:
	TCrossOver(Float64 fsamp);
	virtual ~TCrossOver();
	
	void SetSampleRate(Float64 fsamp);
	
	void filter(Float32 *pinL, Float32 *pinR, Float32 *poutL, Float32 *poutR, UInt32 nsamp);
	void reset();

    TPtr<TDelay> m_dlyL;
	TPtr<TDelay> m_dlyR;

	TPtr<TFilter> m_bpfL;
	TPtr<TFilter> m_hishelfL;

	TPtr<TFilter> m_bpfR;
	TPtr<TFilter> m_hishelfR;

	Float64 m_xatten;
};

#endif // __CROSSOVER_H__

