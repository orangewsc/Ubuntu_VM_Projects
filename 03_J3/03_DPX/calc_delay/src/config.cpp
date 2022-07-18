
#include "config.hpp"


namespace calcdelay{

static struct commonconfig opt=
{
    "eth0",                 //nicdevice
    "",                     // progname;
    "server",               // runningmode;
    "TCP",                  // protocol;
    "255.255.255.0",        // remoteIP;
    HARDWARESTR,            // timestamping;
    'v' + std::to_string(CALC_DELAY_VERSION_MAJOR) + '.' + std::to_string(CALC_DELAY_VERSION_MINOR),                     // version;
    6666,                   // port;
    10,                     // transmitcycle;
    1,                     // transmittime;
    MESSAGESIZE,            // messagesize  /bytes;
    1,                      // printflag;
    0                       // tos
};


std::shared_ptr<Config> Config::p(new Config(opt));
std::shared_ptr<Config> Config::GetInstance()
{
    return p;
}

void Config::ShowVersion()
{
    std::cout << ccfg.version << std::endl;
}

commonconfig Config::GetCfg()
{
    return ccfg;
}

void Config::ShowUsage()
{
    fprintf(stderr,
            "\nusage: %s [options]\n\n"
            " Device\n\n"
            " -i  [NIC name]    e.g: eth0(default)"
            " Running Mode\n\n"
            " -s  [server]      running as server(default)\n"
            " -c  [client]      running as client\n"
            "                   while running as client, server-side IP must folow -c\n"
            " Network Transport\n\n"
            " -T  [TCP]         (default)\n"
            " -U  [UDP]         Broadcast mode(default)\n"
            " --remoteIP        when want to set remoteIP,use --remoteIP\n"
            " -P  [port]        (default 6666)\n"
            " -B  [Byte]        (default 1460)\n"
            " Time Stamping\n\n"
            " -H                HARDWARE (default)\n"
            " -S                SOFTWARE\n"
            " Other Options\n\n"
            " -t  [time/ms]     transmit cycle(default 100ms)\n"
            " -n                trancmit times(default 10s)\n"
            " -m                print messages to stdout, 0-off,1-on(default 1)\n"
            " -v                prints the software version and exits\n"
            " -h                prints this message and exits\n"
            " --tos             set skb proirity,ranges[0, 255](default 0)\n"          
            "\n",
            ccfg.progname.c_str());
}

static int lopt;
struct option Config::longopts[]=
{
    {"help",            no_argument,        NULL,   'h'  },
    {"version",         no_argument,        NULL,   'v'  },
    {"remoteIP",        required_argument,  &lopt,   1   },
    {"cycle",           required_argument,  &lopt,   2   },
    {"tos",             required_argument,  &lopt,   3   },
    {0,                 0,                  0,       0   }
};

bool  Config::ParseCommand(int argc, char *argv[])
{
    char* tmp = strrchr(argv[0], '/');
    tmp = tmp ? tmp + 1 : argv[0];

    ccfg.progname = tmp;
    int ret=0, index = 0;
    while (EOF != (ret = getopt_long(argc, argv, "i:sc:TUP:B:HSt:n:m:vh", longopts, &index)))
    {
        switch (ret)
        {
        case 0:
            switch (lopt)
            {
            case 1:
                ccfg.remoteIP = optarg;
                break;
            case 2:
                ccfg.transmitcycle = atoi(optarg);
                break;
            case 3:
                ccfg.tos = atoi(optarg);
                break;
            default:
                return -1;
                ShowUsage();
                break;
            }
            break;
        case 'i':
            ccfg.nicdevice = optarg;
            break;
        case 's':
            ccfg.runningmode = "server";
            break;
        case 'c':
            ccfg.runningmode = "client";
            ccfg.remoteIP    = optarg;
            break;
        case 'T':
            ccfg.protocol = TCP;
            break;
        case 'U':
            ccfg.protocol = UDP;
            break;
        case 'P':
            ccfg.port = atoi(optarg);
            break;
        case 'B':
            ccfg.messagesize = atoi(optarg);
            break;
        case 'H':
            ccfg.timestamping = HARDWARESTR;
            break;
        case 'S':
            ccfg.timestamping = SOFTWARESTR;
            break;
        case 't':
            ccfg.transmitcycle = atoi(optarg);
            break;
        case 'n':
            ccfg.transmittime = atoi(optarg);
            break;
        case 'm':
            ccfg.printflag = atoi(optarg);
            break;
        case 'v':
            ShowVersion();
            return -1;
            break;
        default:
            ShowUsage();
            return -1;
            break;
        }
    }

    return 0;
}

void Config::ShowCfg()
{
    std::cout << "cfg.nicdevice="       << ccfg.nicdevice        <<std::endl;
    std::cout << "cfg.runningmode="     << ccfg.runningmode      <<std::endl;
    std::cout << "cfg.bytes="           << ccfg.messagesize      <<std::endl;
    std::cout << "cfg.port="            << ccfg.port             <<std::endl;
    std::cout << "cfg.printflag="       << ccfg.printflag        <<std::endl;
    std::cout << "cfg.progname="        << ccfg.progname         <<std::endl;
    std::cout << "cfg.protocol="        << ccfg.protocol         <<std::endl;
    std::cout << "cfg.remoteIP="        << ccfg.remoteIP         <<std::endl;
    std::cout << "cfg.timestamping="    << ccfg.timestamping     <<std::endl;
    std::cout << "cfg.transmitcycle="   << ccfg.transmitcycle    <<std::endl;
    std::cout << "cfg.transmittime="    << ccfg.transmittime     <<std::endl;
    std::cout << "cfg.version="         << ccfg.version          <<std::endl;
}


}        // namespace calcdelay

