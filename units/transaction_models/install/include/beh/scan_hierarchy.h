#pragma once
/**
* @brief The scan_hierarchy class implements the scan_hierachy function for
*   the configuration manager
*/

#define TEST_ATTTYPE_N_PRINT_STRING(T) if(typeid(*attr)==typeid(sc_attribute< T >)){ \
    *m_ofs<<indent<<"\"type\" : \"attribute\","<<endl<<indent<<"\"format\" : \"" << #T <<"\","<<endl \
    <<indent<<"\"value\" : \""<<((sc_attribute< T >*)attr)->value \
    <<"\""<<std::endl;indent.erase(indent.length()-1);*m_ofs<<indent<< "},"<<endl; continue; }
#define TEST_ATTTYPE_N_PRINT(T) if(typeid(*attr)==typeid(sc_attribute< T >)){ \
    *m_ofs<<indent<<"\"type\" : \"attribute\","<<endl<<indent<<"\"format\" : \"" << #T <<"\","<<endl \
    <<indent<<"\"value\" : "<<((sc_attribute< T >*)attr)->value \
    <<std::endl;indent.erase(indent.length()-1);*m_ofs<<indent<< "},"<<endl; continue; }
#define TEST_ATTTYPE_N_PRINT_INT(T) if(typeid(*attr)==typeid(<sc_attribute< T >)){ \
    *m_ofs<<indent<<"\"type\" : \"attribute\","<<endl<<indent<<"\"value\" : "<<(int)(((sc_attribute< T >*)attr)->value)<<std::endl; continue; }
#define TEST_ATTTYPE_N_NOPRINT(T) if(typeid(*attr)==typeid(sc_attribute< T >)){ continue; }

class scan_hierarchy
{
public:

	static std::string indent;
	//static std::map<std::string, bool> seen;
	std::ostream *m_ofs;
   /**
    * @brief Constructor
    */
    scan_hierarchy(ostream *ofs) {
    	m_ofs = ofs;
    	*m_ofs << "{"<<std::endl;
		indent.insert(indent.length(), "\t");
    }

    /**
    * @brief Destructor
    */
    ~scan_hierarchy() {
    	*m_ofs << endl << "}"<<std::endl;

    };

    /**
    * @brief Traverse the entire object sub hierarchy
    */
	void do_scan_hierarchy(sc_object* obj) {
		// static std::string indent;
		static std::map<std::string, bool> seen;

		if (   (strcmp("sc_module",        obj->kind()) == 0)
			|| (strcmp("sc_module_master", obj->kind()) == 0)
			|| (strcmp("sc_module_slave",  obj->kind()) == 0)) {
			*m_ofs << indent << "\"" << obj->name() << "\" : " << endl;
			*m_ofs << indent << "{" << endl;
			indent.insert(indent.length(), "\t");
			*m_ofs << indent << "\"type\" : \"" << obj->kind() << "\"," <<endl;
			*m_ofs << indent << "\"pointer\" : \"" << obj << "\"";
			// For attributes another traversing mechanism is needed.
			sc_attr_cltn& c = obj->attr_cltn();
			if (c.size()>0)
				*m_ofs << "," << endl;
			for (sc_attr_cltn::const_iterator i = c.begin(); i<c.end(); i++) {
			  sc_core::sc_attr_base* attr = *i;
              std::string attrname(obj->name());
              attrname+=".";
			  attrname+=attr->name();
			  if(seen.find(attrname)== seen.end()){
				  seen[attrname]= true;
				  *m_ofs << indent <<"\""<<attrname<<"\" :" << endl;
				  *m_ofs << indent << "{" << endl;
				  indent.insert(indent.length(), "\t");
				  TEST_ATTTYPE_N_PRINT_STRING(std::string)
				  TEST_ATTTYPE_N_PRINT(bool)
				  TEST_ATTTYPE_N_PRINT(char)
				  TEST_ATTTYPE_N_PRINT(int)
				  TEST_ATTTYPE_N_PRINT(short)
				  TEST_ATTTYPE_N_PRINT(long)
				  TEST_ATTTYPE_N_PRINT(long long)
				  TEST_ATTTYPE_N_PRINT(unsigned int)
				  TEST_ATTTYPE_N_PRINT(unsigned short)
				  TEST_ATTTYPE_N_PRINT(unsigned long)
				  TEST_ATTTYPE_N_PRINT(unsigned long long)
				  TEST_ATTTYPE_N_PRINT(float)
				  TEST_ATTTYPE_N_PRINT(double)
				  TEST_ATTTYPE_N_NOPRINT(sc_core::sc_time)
				  *m_ofs<<"# unknown attribute: "<<attrname<<" with typeid "<<typeid(*attr).name()<<" encountered!"<<std::endl;
			  };
		  };

		  // *m_ofs << indent << "{" << endl;
		  std::vector<sc_object*> children = obj->get_child_objects();
		  if (c.size()==0) {
			  if (children.size()>0)
				  *m_ofs << "," << endl;
			  else
				  *m_ofs  << endl;
		  };
		  for (unsigned i = 0; i < children.size(); i++) {
			  if (children[i]) {
				  //indent.insert(indent.length(), "\t");
				  do_scan_hierarchy(children[i]);
				  //indent.erase(indent.length() - 1);
				  if (i<(children.size()-1))
					  *m_ofs << ",";
				  *m_ofs << endl;
			  }
		  }
		  indent.erase(indent.length() - 1);
		  *m_ofs << indent << "}";
		}
		else {
			*m_ofs << indent << "\"" << obj->name() << "\" : " << endl;
			*m_ofs << indent << "{" << endl;
			indent.insert(indent.length(), "\t");
			*m_ofs << indent << "\"type\" : \"" << obj->kind() << "\"," << endl;
			*m_ofs << indent << "\"pointer\" : \"" << obj << "\"" << endl;
			indent.erase(indent.length() - 1);
			*m_ofs << indent << "}";
		}
	}
};

std::string scan_hierarchy::indent ="";
