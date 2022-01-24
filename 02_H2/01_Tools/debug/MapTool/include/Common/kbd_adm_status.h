#ifndef _KBD_ADM_STATUS_H_
#define _KBD_ADM_STATUS_H_

#include <string>
#include "kbd_adm_errcode.h"

namespace adm_kotei {

/**
 * @class Status
 *
 * @brief A general class to denote the return status of an API call. It
 * can either be an OK status for success, or a failure status with error
 * message and error code enum.
*/
class Status {
 public:
  /**
   * @brief Create a success status.
   */
  Status() : code_(OK), msg_() {}
  ~Status(){}

  /**
   * @brief Create a status with the specified error code and msg as a
   * human-readable string containing more detailed information.
   * @param code the error code.
   * @param msg the message associated with the error.
   */
  Status(const ErrorCode code, const std::string &msg) : code_(code), msg_(msg) {}

  /**
   * @brief Create a status with the specified error code and empty msg
   * @param code the error code.
   */
  explicit Status(const ErrorCode code) : code_(code), msg_("") {}

  /**
   * @brief check whether the return status is OK.
   * @returns true if the code is ErrorCode::OK
   *          false otherwise
   */
  bool ok() const { return code_ == OK; }

  /**
   * @brief get the error code
   * @returns the error code
   */
  ErrorCode code() const { return code_; }

  /**
   * @brief defines the logic of testing if two Status are equal
   */
  bool operator==(const Status &rh) const {
    return (this->code_ == rh.code_) && (this->msg_ == rh.msg_);
  }

  /**
   * @brief defines the logic of testing if two Status are unequal
   */
  bool operator!=(const Status &rh) const { return !(*this == rh); }

  /**
   * @brief returns the error message of the status, empty if the status is OK.
   * @returns the error message
   */
  const std::string &error_message() const { return msg_; }

 private:
  ErrorCode code_;  ///< ´íÎóÂë
  std::string msg_; ///< ´íÎóÐÅÏ¢
};


}  // namespace adm_kotei

#endif  // _KBD_ADM_STATUS_H_
