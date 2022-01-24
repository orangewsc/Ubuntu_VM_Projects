#ifndef _KBD_ADM_COMMON_H
#define _KBD_ADM_COMMON_H
/*!
 * \file kbd_adm_common.h
 *
 * \par Description:
 *  Main include file.
 *
*/

#include <cstring>
#include <string>
#include <vector>
#include <list>

#include "kbd_adm_simpletypes.h"
#include "kbd_adm_constants.h"
#include "kbd_adm_structs.h"
#include "kbd_adm_status.h"
#include "kbd_adm_parse_poi.h"

#ifndef SAFE_DELETE
    /* 安全删除一个需调用delete释放的对象 */
    #define SAFE_DELETE(pObject) if(pObject) {delete (pObject); (pObject) = NULL;}
#endif

#ifndef SAFE_DELETE_GROUP
    /* 安全删除一组需调用delete[]释放的对象 */
    #define SAFE_DELETE_GROUP(pObject) if(NULL != pObject) {delete[] (pObject); (pObject) = NULL;}
#endif

#endif /* _KBD_ADM_COMMON_H */
