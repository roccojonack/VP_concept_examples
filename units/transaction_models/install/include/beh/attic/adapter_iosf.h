
template<unsigned int INPUT_BUSWIDTH, unsigned int OUTPUT_BUSWIDTH>
class ForwardingSocketTLM2IOSF: public TLM_BASE::vpCommon
{
  public:
  ForwardingSocketTLM2IOSF(sc_core::sc_module_name name, sc_dt::int64 addressOffset =
      0, sc_dt::int64 id = -1,
      bool doRemoveByteEn = false, bool traceEnable = false);

  TLM_IA::IosfPrimaryInitiatorSocket<OUTPUT_BUSWIDTH> initiator_socket;
  tlm_utils::simple_target_socket<ForwardingSocketTLM2IOSF<INPUT_BUSWIDTH, OUTPUT_BUSWIDTH>, INPUT_BUSWIDTH> target_socket;

  void convert_b_transport(tlm::tlm_generic_payload& trans, sc_time& delay);
  unsigned int convert_transport_dbg(tlm::tlm_generic_payload& trans);
  bool m_traceEnable;
};

template<unsigned int INPUT_BUSWIDTH, unsigned int OUTPUT_BUSWIDTH>
class ForwardingSocketIOSF2TLM: public TLM_BASE::vpCommon
{
public:
  ForwardingSocketIOSF2TLM(sc_core::sc_module_name name);

  tlm_utils::simple_initiator_socket<ForwardingSocketIOSF2TLM<INPUT_BUSWIDTH, OUTPUT_BUSWIDTH>, OUTPUT_BUSWIDTH> initiator_socket;
  TLM_IA::IosfPrimaryTargetSocket<INPUT_BUSWIDTH> target_socket;

  TLM_BASE::AddressSpace mAddressSpaceMem;
  TLM_BASE::AddressSpace mAddressSpaceCfg;
  TLM_BASE::AddressSpace mAddressSpaceIO;
  int forwardWriteCbMem   (TLM_IA::tPayload &p);
  int forwardReadCbMem    (TLM_IA::tPayload &p);
  int forwardWriteCbCfg   (TLM_IA::tPayload &p);
  int forwardReadCbCfg    (TLM_IA::tPayload &p);
  int forwardWriteCbIO    (TLM_IA::tPayload &p);
  int forwardReadCbIO     (TLM_IA::tPayload &p);
  int forwardWriteDbgCbMem(TLM_IA::tPayload &p);
  int forwardReadDbgCbMem (TLM_IA::tPayload &p);
  int forwardWriteDbgCbCfg(TLM_IA::tPayload &p);
  int forwardReadDbgCbCfg (TLM_IA::tPayload &p);
  int forwardWriteDbgCbIO (TLM_IA::tPayload &p);
  int forwardReadDbgCbIO  (TLM_IA::tPayload &p);
  sc_time m_time;
  bool m_traceEnable;
  sc_dt::uint64 	_b_transport_count;
  sc_dt::uint64 	_transport_dbg_count;
  sc_dt::uint64 	_nb_transport_count;
  virtual void end_of_simulation()
  {
	  print_counters();
  };

  /*! \brief The print_counters function
   *
   * The function is returning the address offset
   */
  void print_counters()
  {
	  std::cout << std::dec
			<< " There are " << _b_transport_count
			  << " b_transport calls, " << _transport_dbg_count
			  << " transport_dbg calls, " << "0 DMI calls"
			  << " over socket: " << name() << std::endl;
  };
};

template<unsigned int INPUT_BUSWIDTH, unsigned int OUTPUT_BUSWIDTH>
class ForwardingSocketIOSF: public TLM_BASE::vpCommon
{
public:
  ForwardingSocketIOSF(sc_core::sc_module_name name);

  TLM_IA::IosfPrimaryTargetSocket<INPUT_BUSWIDTH> target_socket;
  TLM_IA::IosfPrimaryInitiatorSocket<OUTPUT_BUSWIDTH> initiator_socket;

  TLM_BASE::AddressSpace mAddressSpaceMem;
  TLM_BASE::AddressSpace mAddressSpaceCfg;
  TLM_BASE::AddressSpace mAddressSpaceIO;
  int forwardWriteCbMem   (TLM_IA::tPayload &p);
  int forwardReadCbMem    (TLM_IA::tPayload &p);
  int forwardWriteCbCfg   (TLM_IA::tPayload &p);
  int forwardReadCbCfg    (TLM_IA::tPayload &p);
  int forwardWriteCbIO    (TLM_IA::tPayload &p);
  int forwardReadCbIO  	  (TLM_IA::tPayload &p);
  int forwardWriteDbgCbMem(TLM_IA::tPayload &p);
  int forwardReadDbgCbMem (TLM_IA::tPayload &p);
  int forwardWriteDbgCbCfg(TLM_IA::tPayload &p);
  int forwardReadDbgCbCfg (TLM_IA::tPayload &p);
  int forwardWriteDbgCbIO (TLM_IA::tPayload &p);
  int forwardReadDbgCbIO  (TLM_IA::tPayload &p);
  sc_time m_time;
  bool m_traceEnable;
  sc_dt::uint64 	_b_transport_count;
  sc_dt::uint64 	_transport_dbg_count;
  virtual void end_of_simulation()
  {
  	print_counters();
  };

  /*! \brief The print_counters function
   *
   * The function is returning the address offset
   */
  void print_counters()
  {
	  cout << " There are " << _b_transport_count
			  << " b_transport calls, " << _transport_dbg_count
			  << " transport_dbg calls, " << "0 DMI calls"
			  << " over socket: " << name() << endl;
  };
};
