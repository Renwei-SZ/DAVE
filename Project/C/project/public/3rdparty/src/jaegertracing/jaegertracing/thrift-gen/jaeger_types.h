/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef jaeger_TYPES_H
#define jaeger_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>




namespace jaegertracing { namespace thrift {

struct TagType {
  enum type {
    STRING = 0,
    DOUBLE = 1,
    BOOL = 2,
    LONG = 3,
    BINARY = 4
  };
};

extern const std::map<int, const char*> _TagType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TagType::type& val);

struct SpanRefType {
  enum type {
    CHILD_OF = 0,
    FOLLOWS_FROM = 1
  };
};

extern const std::map<int, const char*> _SpanRefType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const SpanRefType::type& val);

class Tag;

class Log;

class SpanRef;

class Span;

class Process;

class Batch;

class BatchSubmitResponse;

typedef struct _Tag__isset {
  _Tag__isset() : vStr(false), vDouble(false), vBool(false), vLong(false), vBinary(false) {}
  bool vStr :1;
  bool vDouble :1;
  bool vBool :1;
  bool vLong :1;
  bool vBinary :1;
} _Tag__isset;

class Tag : public virtual ::apache::thrift::TBase {
 public:

  Tag(const Tag&);
  Tag& operator=(const Tag&);
  Tag() : key(), vType((TagType::type)0), vStr(), vDouble(0), vBool(0), vLong(0), vBinary() {
  }

  virtual ~Tag() throw();
  std::string key;
  TagType::type vType;
  std::string vStr;
  double vDouble;
  bool vBool;
  int64_t vLong;
  std::string vBinary;

  _Tag__isset __isset;

  void __set_key(const std::string& val);

  void __set_vType(const TagType::type val);

  void __set_vStr(const std::string& val);

  void __set_vDouble(const double val);

  void __set_vBool(const bool val);

  void __set_vLong(const int64_t val);

  void __set_vBinary(const std::string& val);

  bool operator == (const Tag & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(vType == rhs.vType))
      return false;
    if (__isset.vStr != rhs.__isset.vStr)
      return false;
    else if (__isset.vStr && !(vStr == rhs.vStr))
      return false;
    if (__isset.vDouble != rhs.__isset.vDouble)
      return false;
    else if (__isset.vDouble && !(vDouble == rhs.vDouble))
      return false;
    if (__isset.vBool != rhs.__isset.vBool)
      return false;
    else if (__isset.vBool && !(vBool == rhs.vBool))
      return false;
    if (__isset.vLong != rhs.__isset.vLong)
      return false;
    else if (__isset.vLong && !(vLong == rhs.vLong))
      return false;
    if (__isset.vBinary != rhs.__isset.vBinary)
      return false;
    else if (__isset.vBinary && !(vBinary == rhs.vBinary))
      return false;
    return true;
  }
  bool operator != (const Tag &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Tag & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Tag &a, Tag &b);

std::ostream& operator<<(std::ostream& out, const Tag& obj);


class Log : public virtual ::apache::thrift::TBase {
 public:

  Log(const Log&);
  Log& operator=(const Log&);
  Log() : timestamp(0) {
  }

  virtual ~Log() throw();
  int64_t timestamp;
  std::vector<Tag>  fields;

  void __set_timestamp(const int64_t val);

  void __set_fields(const std::vector<Tag> & val);

  bool operator == (const Log & rhs) const
  {
    if (!(timestamp == rhs.timestamp))
      return false;
    if (!(fields == rhs.fields))
      return false;
    return true;
  }
  bool operator != (const Log &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Log & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Log &a, Log &b);

std::ostream& operator<<(std::ostream& out, const Log& obj);


class SpanRef : public virtual ::apache::thrift::TBase {
 public:

  SpanRef(const SpanRef&);
  SpanRef& operator=(const SpanRef&);
  SpanRef() : refType((SpanRefType::type)0), traceIdLow(0), traceIdHigh(0), spanId(0) {
  }

  virtual ~SpanRef() throw();
  SpanRefType::type refType;
  int64_t traceIdLow;
  int64_t traceIdHigh;
  int64_t spanId;

  void __set_refType(const SpanRefType::type val);

  void __set_traceIdLow(const int64_t val);

  void __set_traceIdHigh(const int64_t val);

  void __set_spanId(const int64_t val);

  bool operator == (const SpanRef & rhs) const
  {
    if (!(refType == rhs.refType))
      return false;
    if (!(traceIdLow == rhs.traceIdLow))
      return false;
    if (!(traceIdHigh == rhs.traceIdHigh))
      return false;
    if (!(spanId == rhs.spanId))
      return false;
    return true;
  }
  bool operator != (const SpanRef &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SpanRef & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SpanRef &a, SpanRef &b);

std::ostream& operator<<(std::ostream& out, const SpanRef& obj);

typedef struct _Span__isset {
  _Span__isset() : references(false), tags(false), logs(false) {}
  bool references :1;
  bool tags :1;
  bool logs :1;
} _Span__isset;

class Span : public virtual ::apache::thrift::TBase {
 public:

  Span(const Span&);
  Span& operator=(const Span&);
  Span() : traceIdLow(0), traceIdHigh(0), spanId(0), parentSpanId(0), operationName(), flags(0), startTime(0), duration(0) {
  }

  virtual ~Span() throw();
  int64_t traceIdLow;
  int64_t traceIdHigh;
  int64_t spanId;
  int64_t parentSpanId;
  std::string operationName;
  std::vector<SpanRef>  references;
  int32_t flags;
  int64_t startTime;
  int64_t duration;
  std::vector<Tag>  tags;
  std::vector<Log>  logs;

  _Span__isset __isset;

  void __set_traceIdLow(const int64_t val);

  void __set_traceIdHigh(const int64_t val);

  void __set_spanId(const int64_t val);

  void __set_parentSpanId(const int64_t val);

  void __set_operationName(const std::string& val);

  void __set_references(const std::vector<SpanRef> & val);

  void __set_flags(const int32_t val);

  void __set_startTime(const int64_t val);

  void __set_duration(const int64_t val);

  void __set_tags(const std::vector<Tag> & val);

  void __set_logs(const std::vector<Log> & val);

  bool operator == (const Span & rhs) const
  {
    if (!(traceIdLow == rhs.traceIdLow))
      return false;
    if (!(traceIdHigh == rhs.traceIdHigh))
      return false;
    if (!(spanId == rhs.spanId))
      return false;
    if (!(parentSpanId == rhs.parentSpanId))
      return false;
    if (!(operationName == rhs.operationName))
      return false;
    if (__isset.references != rhs.__isset.references)
      return false;
    else if (__isset.references && !(references == rhs.references))
      return false;
    if (!(flags == rhs.flags))
      return false;
    if (!(startTime == rhs.startTime))
      return false;
    if (!(duration == rhs.duration))
      return false;
    if (__isset.tags != rhs.__isset.tags)
      return false;
    else if (__isset.tags && !(tags == rhs.tags))
      return false;
    if (__isset.logs != rhs.__isset.logs)
      return false;
    else if (__isset.logs && !(logs == rhs.logs))
      return false;
    return true;
  }
  bool operator != (const Span &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Span & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Span &a, Span &b);

std::ostream& operator<<(std::ostream& out, const Span& obj);

typedef struct _Process__isset {
  _Process__isset() : tags(false) {}
  bool tags :1;
} _Process__isset;

class Process : public virtual ::apache::thrift::TBase {
 public:

  Process(const Process&);
  Process& operator=(const Process&);
  Process() : serviceName() {
  }

  virtual ~Process() throw();
  std::string serviceName;
  std::vector<Tag>  tags;

  _Process__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_tags(const std::vector<Tag> & val);

  bool operator == (const Process & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    if (__isset.tags != rhs.__isset.tags)
      return false;
    else if (__isset.tags && !(tags == rhs.tags))
      return false;
    return true;
  }
  bool operator != (const Process &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Process & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Process &a, Process &b);

std::ostream& operator<<(std::ostream& out, const Process& obj);


class Batch : public virtual ::apache::thrift::TBase {
 public:

  Batch(const Batch&);
  Batch& operator=(const Batch&);
  Batch() {
  }

  virtual ~Batch() throw();
  Process process;
  std::vector<Span>  spans;

  void __set_process(const Process& val);

  void __set_spans(const std::vector<Span> & val);

  bool operator == (const Batch & rhs) const
  {
    if (!(process == rhs.process))
      return false;
    if (!(spans == rhs.spans))
      return false;
    return true;
  }
  bool operator != (const Batch &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Batch & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Batch &a, Batch &b);

std::ostream& operator<<(std::ostream& out, const Batch& obj);


class BatchSubmitResponse : public virtual ::apache::thrift::TBase {
 public:

  BatchSubmitResponse(const BatchSubmitResponse&);
  BatchSubmitResponse& operator=(const BatchSubmitResponse&);
  BatchSubmitResponse() : ok(0) {
  }

  virtual ~BatchSubmitResponse() throw();
  bool ok;

  void __set_ok(const bool val);

  bool operator == (const BatchSubmitResponse & rhs) const
  {
    if (!(ok == rhs.ok))
      return false;
    return true;
  }
  bool operator != (const BatchSubmitResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BatchSubmitResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(BatchSubmitResponse &a, BatchSubmitResponse &b);

std::ostream& operator<<(std::ostream& out, const BatchSubmitResponse& obj);

}} // namespace

#endif
