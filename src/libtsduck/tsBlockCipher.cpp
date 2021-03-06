//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2018, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------

#include "tsBlockCipher.h"
#include "tsByteBlock.h"
TSDUCK_SOURCE;


//----------------------------------------------------------------------------
// Encrypt one block of data in place.
//----------------------------------------------------------------------------

bool ts::BlockCipher::encryptInPlace(void* data, size_t data_length, size_t* max_actual_length)
{
    const ByteBlock plain(data, data_length);
    const size_t cipher_max_size = max_actual_length != 0 ? *max_actual_length : data_length;
    return encrypt(plain.data(), plain.size(), data, cipher_max_size, max_actual_length);
}


//----------------------------------------------------------------------------
// Decrypt one block of data in place.
//----------------------------------------------------------------------------

bool ts::BlockCipher::decryptInPlace(void* data, size_t data_length, size_t* max_actual_length)
{
    const ByteBlock cipher(data, data_length);
    const size_t plain_max_size = max_actual_length != 0 ? *max_actual_length : data_length;
    return decrypt(cipher.data(), cipher.size(), data, plain_max_size, max_actual_length);
}
