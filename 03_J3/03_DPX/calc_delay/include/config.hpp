#ifndef __CONFIG_H
#define __CONFIG_H

#include "version_config.h"
#include "common.h"

namespace calcdelay{

class Config
{
    private:
        explicit Config(commonconfig &opt):ccfg(opt){}
        static  std::shared_ptr<Config>  p;
        static struct option longopts[];
        commonconfig         ccfg; 
    public:
        static  std::shared_ptr<Config> GetInstance();
        bool    ParseCommand(int argc, char *argv[]);
        void    ShowUsage();
        void    ShowVersion();
        void    ShowCfg();
        commonconfig GetCfg();
        Config(const Config &) = delete;
        Config& operator=(const Config&) = delete;
};


}     //namespace calcdelay


#endif