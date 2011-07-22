/*
 * GeoIP C library binding for nodejs
 *
 * Licensed under the GNU LGPL 2.1 license
 */                                              

#ifndef NODE_GEOIP_COUNTRY6_H
#define NODE_GEOIP_COUNTRY6_H

#include <v8.h>
#include <node.h>
#include "node_geoip.h"

using namespace v8;
using namespace node;

namespace geoip {
  class Country6: ObjectWrap
  {
    private:
      GeoIP *db;

      int db_edition;

      static Persistent<FunctionTemplate> constructor_template;

    protected:
      static Handle<Value> New(const Arguments& args);

    public:
      static void Init(Handle<Object> target);

      static Handle<Value> lookupSync(const Arguments& args);

      static Handle<Value> lookup(const Arguments& args);

      static int EIO_Country(eio_req *req);

      static int EIO_AfterCountry(eio_req *req);
      
      static Handle<Value> update(const Arguments &args);

      static Handle<Value> close(const Arguments &args);
  };
}

struct country6_baton_t {
  geoip::Country6 * c;
  char host_cstr[256];
  int country_id;
  Persistent<Function> cb;
};

#endif /* NODE_GEOIP_COUNTRY6_H */