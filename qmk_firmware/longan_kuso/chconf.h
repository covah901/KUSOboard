/* Copyright 2020 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define CH_CFG_ST_RESOLUTION 16

#define CH_CFG_ST_FREQUENCY 10000

#define CH_CFG_USE_TM TRUE

#define CH_CFG_USE_REGISTRY TRUE

#define CH_CFG_USE_WAITEXIT TRUE

#define CH_CFG_USE_CONDVARS TRUE

#define CH_CFG_USE_MESSAGES TRUE

#define CH_CFG_USE_MAILBOXES TRUE

#define CH_CFG_USE_HEAP TRUE

#define CH_CFG_USE_MEMPOOLS TRUE

#define CH_CFG_USE_OBJ_FIFOS TRUE

#define CH_CFG_USE_PIPES TRUE

#define CH_CFG_USE_OBJ_CACHES TRUE

#define CH_CFG_USE_DELEGATES TRUE

#define CH_CFG_USE_JOBS TRUE

#define CH_CFG_USE_FACTORY TRUE

#define CH_CFG_FACTORY_OBJECTS_REGISTRY TRUE

#define CH_CFG_FACTORY_GENERIC_BUFFERS TRUE

#define CH_CFG_FACTORY_SEMAPHORES TRUE

#define CH_CFG_FACTORY_MAILBOXES TRUE

#define CH_CFG_FACTORY_OBJ_FIFOS TRUE

#define CH_CFG_FACTORY_PIPES TRUE

#define CH_DBG_ENABLE_STACK_CHECK FALSE

#include_next <chconf.h>
