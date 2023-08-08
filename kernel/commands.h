#ifndef COMMANDS_H
#define COMMANDS_H

void command_help();
void command_mkdir(const char* name);
void command_rm(const char* name);
void command_ls();
void command_cfile(const char* name);
void command_efile(const char* name);
void handle_command(const char* command);

#endif
