#include "tcp_scpi.h"

#include <Arduino.h>

using namespace scpi_rp;

TCPInterface::TCPInterface() : m_client(nullptr) {}

TCPInterface::~TCPInterface() {}

int TCPInterface::init(Client *client) {
  m_client = client;
  return 0;
}

scpi_size TCPInterface::write(const uint8_t *_data, scpi_size _size) {
  scpi_size pos = 0;
  scpi_size s = _size;
  while (pos < _size && m_client) {
    auto sent = m_client->write(_data + pos, s);
    pos += sent;
    s -= sent;
  }
  return pos;
}

scpi_size TCPInterface::readToBuffer() {
  scpi_size rs = 0;
  while (m_client && m_client->available() && m_bufferSize < BASE_IO_BUFFER_SIZE) {
    m_buffer[m_bufferSize++] = m_client->read();
    rs++;
    if (m_bufferSize >= 2 && m_buffer[m_bufferSize - 2] == '\r' &&
        m_buffer[m_bufferSize - 1] == '\n') {
      break;
    }
  }
  return rs;
}
