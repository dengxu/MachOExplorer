//
// Created by everettjf on 2017/3/31.
//

#ifndef MACHOEXPLORER_LOADCOMMAND_ENCRYPTION_INFO_H
#define MACHOEXPLORER_LOADCOMMAND_ENCRYPTION_INFO_H

#include "loadcommand.h"

MOEX_NAMESPACE_BEGIN

class LoadCommand_LC_ENCRYPTION_INFO : public LoadCommandImpl<encryption_info_command>{
public:
    std::string GetTypeName() override{ return "encryption_info_command";}
    std::string GetDisplayName() override{ return "encryption_info";}
    std::string GetDescription() override{
        return boost::str(boost::format("%1%(type=%2%,size=%3%,crypt offset=%4%, crypt size=%5%, crypt id=%6%)")
                          % this->GetDisplayName()
                          % hp::GetLoadCommandType(offset_->cmd)
                          % offset_->cmdsize
                          % cmd_->cryptoff
                          % cmd_->cryptsize
                          % cmd_->cryptid
        );
    }
};

class LoadCommand_LC_ENCRYPTION_INFO_64 : public LoadCommandImpl<encryption_info_command_64>{
public:
    std::string GetTypeName() override{ return "encryption_info_command_64";}
    std::string GetDisplayName() override{ return "encryption_info";}
    std::string GetDescription() override{
        return boost::str(boost::format("%1%(type=%2%,size=%3%,crypt offset=%4%, crypt size=%5%, crypt id=%6%)")
                          % this->GetDisplayName()
                          % hp::GetLoadCommandType(offset_->cmd)
                          % offset_->cmdsize
                          % cmd_->cryptoff
                          % cmd_->cryptsize
                          % cmd_->cryptid
        );
    }
};

class LoadCommandEncryptionInfo{
private:
    LoadCommand_LC_ENCRYPTION_INFO *info_ = nullptr;
    LoadCommand_LC_ENCRYPTION_INFO_64 *info64_ = nullptr;
    bool is64_ = false;

    encryption_info_command *data_ = nullptr;
public:
    encryption_info_command *data(){return data_;};

    LoadCommandEncryptionInfo(LoadCommand * cmd,bool is64){
        is64_ = is64;
        if(is64){
            info_ = static_cast<moex::LoadCommand_LC_ENCRYPTION_INFO*>(cmd);
            data_ = (encryption_info_command*)info_->offset();
        }else{
            info64_ = static_cast<moex::LoadCommand_LC_ENCRYPTION_INFO_64*>(cmd);
            data_ = (encryption_info_command*)info64_->offset();
        }
    }
};



MOEX_NAMESPACE_END
#endif //MACHOEXPLORER_LOADCOMMAND_ENCRYPTION_INFO_H
