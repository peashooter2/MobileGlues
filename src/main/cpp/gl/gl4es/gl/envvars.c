#include "envvars.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
//----------------------------------------------------------------------------
const char* GL4ES_GetEnvVar(const char *name)
{
	return getenv(name);
}
//----------------------------------------------------------------------------
int GL4ES_HasEnvVar(const char *name)
{
	return GL4ES_GetEnvVar(name)!=NULL;
}
//----------------------------------------------------------------------------
int GL4ES_ReturnEnvVarInt(const char *name)
{
	const char *s=GL4ES_GetEnvVar(name);
	return s ? atoi(s) : 0;
}
//----------------------------------------------------------------------------
int GL4ES_ReturnEnvVarIntDef(const char *name,int def)
{
	const char *s=GL4ES_GetEnvVar(name);
	return s ? atoi(s) : def;
}
//----------------------------------------------------------------------------
int GL4ES_IsEnvVarTrue(const char *name)
{
	const char *s=GL4ES_GetEnvVar(name);
	return s && atoi(s)!=0;
}
//----------------------------------------------------------------------------
int GL4ES_IsEnvVarFalse(const char *name)
{
	const char *s=GL4ES_GetEnvVar(name);
	return s && *s=='0';
}
//----------------------------------------------------------------------------
int GL4ES_IsEnvVarInt(const char *name,int i)
{
	const char *s=GL4ES_GetEnvVar(name);
	return s && atoi(s)==i;
}
//----------------------------------------------------------------------------
int GL4ES_GetEnvVarInt(const char *name,int *i,int def)
{
	const char *s=GL4ES_GetEnvVar(name);
	*i=s ? atoi(s) : def;
	return s!=NULL;
}
//----------------------------------------------------------------------------
int GL4ES_GetEnvVarBool(const char *name,int *b,int def)
{
	const char *s=GL4ES_GetEnvVar(name);
	*b=s ? atoi(s) : def;
	if(*b) *b=1;
	return s!=NULL;
}
//----------------------------------------------------------------------------
int GL4ES_GetEnvVarFloat(const char *name,float *f,float def)
{
	const char *s=GL4ES_GetEnvVar(name);
	*f=s ? atof(s) : def;
	return s!=NULL;
}
//----------------------------------------------------------------------------
int GL4ES_GetEnvVarFmt(const char *name,const char *fmt,...)
{
	int cnt=0;
	const char *s=GL4ES_GetEnvVar(name);
	if(s) {
		va_list args;
  	va_start(args,fmt);
  	cnt=vsscanf(s,fmt,args);
  	va_end(args);
	}
	return cnt;
}
//----------------------------------------------------------------------------
