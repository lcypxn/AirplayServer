/* -*- Mode: C; tab-width: 4; c-file-style: "bsd"; c-basic-offset: 4; fill-column: 108 -*-
 *
 * Copyright (c) 2002-2004 Apple Computer, Inc. All rights reserved.
 * Copyright (c) 2018 Apple Computer, Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __cfParse_h
#define __cfParse_h

// Structure of a configuration file verb
typedef struct {
	char *name;
	int minHunks, maxHunks;
	mDNSBool (*handler)(void *context, const char *cfName, char **hunks, int numHunks, int lineno);
} ConfigFileVerb;

// Provided by RelayParse.c
mDNSexport mDNSBool cfParse(void *context, const char *cfName, ConfigFileVerb *verbs, int numVerbs);

#endif // __cfParse_h
