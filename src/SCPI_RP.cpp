/*!
 *  @file SCPI_RP.cpp
 *
 *  This is a library for interacting with Red Pitaya boards via SCPI server
 *
 *
 *  Written by Red Pitaya Industries.
 *
 *  MIT license, all text above must be included in any redistribution
 */

#include "SCPI_RP.h"

#include "common/base_io.h"
#include "tcp/tcp_scpi.h"
#include "uart/uart_scpi.h"

using namespace scpi_rp;

BaseIO *g_base_io = nullptr;
bool g_base_io_owned = false;

SCPIRedPitaya::SCPIRedPitaya() {}

SCPIRedPitaya::~SCPIRedPitaya() {
  if (g_base_io_owned) delete g_base_io;
}

void SCPIRedPitaya::initStream(BaseIO *io) {
  g_base_io = io;
  system.setInterface(io);
  dio.setInterface(io);
  aio.setInterface(io);
  daisy.setInterface(io);
  pll.setInterface(io);
  system_led.setInterface(io);
  gen.setInterface(io);
  acq.control.setInterface(io);
  acq.settings.setInterface(io);
  acq.data.setInterface(io);
  acq.trigger.setInterface(io);
  acq.dma.settings.setInterface(io);
  acq.dma.data.setInterface(io);
}

void SCPIRedPitaya::initStream(Transport transport, void *ctx) {
  switch (transport) {
    case Transport::UART: {
      UARTInterface *u = new UARTInterface();
      u->init(static_cast<Stream *>(ctx));
      g_base_io_owned = true;
      initStream(static_cast<BaseIO *>(u));
      break;
    }
    case Transport::TCP: {
      TCPInterface *t = new TCPInterface();
      t->init(static_cast<Client *>(ctx));
      g_base_io_owned = true;
      initStream(static_cast<BaseIO *>(t));
      break;
    }
  }
}
