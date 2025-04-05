#ifndef _GL4ES_ENVVARS_H_
#define _GL4ES_ENVVARS_H_
//----------------------------------------------------------------------------
const char* GL4ES_GetEnvVar(const char *name);
//----------------------------------------------------------------------------
int GL4ES_HasEnvVar(const char *name);
int GL4ES_ReturnEnvVarInt(const char *name);
int GL4ES_ReturnEnvVarIntDef(const char *name,int def);
//----------------------------------------------------------------------------
int GL4ES_IsEnvVarTrue(const char *name);
int GL4ES_IsEnvVarFalse(const char *name);
int GL4ES_IsEnvVarInt(const char *name,int i);
//----------------------------------------------------------------------------
int GL4ES_GetEnvVarInt(const char *name,int *i,int def);
int GL4ES_GetEnvVarBool(const char *name,int *b,int def);
int GL4ES_GetEnvVarFloat(const char *name,float *f,float def);
//----------------------------------------------------------------------------
int GL4ES_GetEnvVarFmt(const char *name,const char *fmt,...);
//----------------------------------------------------------------------------
#endif
