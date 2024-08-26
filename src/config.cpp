#include "config.hpp"
#include "log.hpp"

void Config_init(void)
{
    CONFIG.log_type = log_level_init();
}