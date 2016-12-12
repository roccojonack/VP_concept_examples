#pragma once

#include <string>
#include <stdint.h>

namespace TLM2_COMMON {
/*! the interface to allow overriding the built-in plain file i/o in the tlm2_sprarsemem
 *
 */
struct custom_io_if {
  //! the virtual destructor to make sure overloading runs fine
  virtual ~custom_io_if(){}
  /*!\ brief the function being called by the sparse memory to read in the content of page
   *
   * \param fileName the file name of the file to be read
   * \param size size of the array to be read
   * \param data the array of size size where the read data should be stored to
   */
  virtual void read_from_file(const std::string fileName, size_t size, uint8_t* data) = 0;
  /*!\ brief the function being called by the sparse memory to write in the content of page
   *
   * \param fileName the file name of the file to be written
   * \param size size of the array to be written
   * \param data the array of size size which contains the data to be written
   */
  virtual void write_to_file(const std::string fileName, size_t size, uint8_t* data) = 0;

};
}; //namespace TLM2_COMMON

