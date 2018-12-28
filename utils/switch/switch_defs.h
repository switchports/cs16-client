#pragma once

#ifndef SWITCH_DEFS_H
#define SWITCH_DEFS_H

#ifdef __cplusplus
extern "C"
{
#endif

#define PATH_MAX 256

#ifdef CLIENT_DLL
#define gpGlobals cl_gpGlobals
#define g_engfuncs g_cl_engfuncs
#define g_physfuncs g_cl_physfuncs
#else
#define gpGlobals sv_gpGlobals
#define g_engfuncs g_sv_engfuncs
#define g_physfuncs g_sv_physfuncs
#endif

typedef struct dllexport_s
{
	const char *name;
	void *func;
} dllexport_t;

int dll_register( const char *name, dllexport_t *exports );

#ifdef __cplusplus
}
#endif

#endif