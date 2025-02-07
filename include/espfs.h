#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct EspFsConfig {
    const void* memAddr;
    const char* partLabel;
};

typedef struct EspFsConfig EspFsConfig;
typedef struct EspFs EspFs;
typedef struct EspFsFile EspFsFile;

EspFs* espFsInit(EspFsConfig* conf);
void espFsDeinit(EspFs* fs);
EspFsFile* espFsOpen(EspFs* fs, const char *fileName);
int espFsFlags(EspFsFile *fh);
int espFsRead(EspFsFile *fh, char *buff, int len);
int espFsSeek(EspFsFile *fh, long offset, int mode);
bool espFsIsCompressed(EspFsFile *fh);
int espFsAccess(EspFsFile *fh, void **buf);
int espFsFilesize(EspFsFile *fh);
void espFsClose(EspFsFile *fh);

#ifdef __cplusplus
}
#endif
