/*
 * Copyright (C) 2012 Square, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef fileio_h
#define fileio_h

#include"types.h"

/**
 * File utility primitives somewhat patterned on RandomAccessFile.
 */


bool FileIo_seek(FILE* file, uint32_t position);

/** Writes buffer to file, flushes to media. */
bool FileIo_write(FILE* file, const byte* buffer, uint32_t buffer_offset,
    uint32_t length);

bool FileIo_read(FILE* file, void* buffer, uint32_t buffer_offset,
    uint32_t length);

/** @return file length or -1 on error */
off_t FileIo_getLength(FILE* file);

/** Writes length 0s to file, flushes to media. Starts at current file position. */
/** @param length must be multiple of 4. */
bool FileIo_writeZeros(FILE* file, uint32_t length);

/** Some systems allow the file length to be adjusted using truncate, as
 * some JVMs do for RandomAccessFile.setLength */
bool FileIo_setLength(FILE* file, uint32_t length);

/** Will copy part of a file to another offset, the caller is responsible for
 * checking that there is enough data from the source to cover length.
 * The parts to transfer may not overlap.
 * TODO: investigate whether fread and fwrite make efficient use of the
 *       FILE's read cache.
 **/
bool FileIo_transferTo(FILE *file, uint32_t source, uint32_t destination,
    uint32_t length);

#endif
