// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto

#include "msg.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

class EchoMsgDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<EchoMsg> _instance;
} _EchoMsg_default_instance_;
static void InitDefaultsEchoMsg_msg_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_EchoMsg_default_instance_;
    new (ptr) ::EchoMsg();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::EchoMsg::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_EchoMsg_msg_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsEchoMsg_msg_2eproto}, {}};

void InitDefaults_msg_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_EchoMsg_msg_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_msg_2eproto[1];
constexpr ::google::protobuf::EnumDescriptor const** file_level_enum_descriptors_msg_2eproto = nullptr;
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_msg_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_msg_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::EchoMsg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::EchoMsg, msg_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::EchoMsg)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_EchoMsg_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_msg_2eproto = {
  {}, AddDescriptors_msg_2eproto, "msg.proto", schemas,
  file_default_instances, TableStruct_msg_2eproto::offsets,
  file_level_metadata_msg_2eproto, 1, file_level_enum_descriptors_msg_2eproto, file_level_service_descriptors_msg_2eproto,
};

const char descriptor_table_protodef_msg_2eproto[] =
  "\n\tmsg.proto\"\026\n\007EchoMsg\022\013\n\003msg\030\001 \001(\tb\006pro"
  "to3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_msg_2eproto = {
  false, InitDefaults_msg_2eproto, 
  descriptor_table_protodef_msg_2eproto,
  "msg.proto", &assign_descriptors_table_msg_2eproto, 43,
};

void AddDescriptors_msg_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_msg_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_msg_2eproto = []() { AddDescriptors_msg_2eproto(); return true; }();

// ===================================================================

void EchoMsg::InitAsDefaultInstance() {
}
class EchoMsg::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int EchoMsg::kMsgFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

EchoMsg::EchoMsg()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:EchoMsg)
}
EchoMsg::EchoMsg(const EchoMsg& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.msg().size() > 0) {
    msg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.msg_);
  }
  // @@protoc_insertion_point(copy_constructor:EchoMsg)
}

void EchoMsg::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_EchoMsg_msg_2eproto.base);
  msg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

EchoMsg::~EchoMsg() {
  // @@protoc_insertion_point(destructor:EchoMsg)
  SharedDtor();
}

void EchoMsg::SharedDtor() {
  msg_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void EchoMsg::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const EchoMsg& EchoMsg::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_EchoMsg_msg_2eproto.base);
  return *internal_default_instance();
}


void EchoMsg::Clear() {
// @@protoc_insertion_point(message_clear_start:EchoMsg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* EchoMsg::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<EchoMsg*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string msg = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("EchoMsg.msg");
        object = msg->mutable_msg();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool EchoMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:EchoMsg)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string msg = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_msg()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->msg().data(), static_cast<int>(this->msg().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "EchoMsg.msg"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:EchoMsg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:EchoMsg)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void EchoMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:EchoMsg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string msg = 1;
  if (this->msg().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->msg().data(), static_cast<int>(this->msg().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "EchoMsg.msg");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->msg(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:EchoMsg)
}

::google::protobuf::uint8* EchoMsg::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:EchoMsg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string msg = 1;
  if (this->msg().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->msg().data(), static_cast<int>(this->msg().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "EchoMsg.msg");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->msg(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:EchoMsg)
  return target;
}

size_t EchoMsg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:EchoMsg)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string msg = 1;
  if (this->msg().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->msg());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EchoMsg::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:EchoMsg)
  GOOGLE_DCHECK_NE(&from, this);
  const EchoMsg* source =
      ::google::protobuf::DynamicCastToGenerated<EchoMsg>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:EchoMsg)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:EchoMsg)
    MergeFrom(*source);
  }
}

void EchoMsg::MergeFrom(const EchoMsg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:EchoMsg)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.msg().size() > 0) {

    msg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.msg_);
  }
}

void EchoMsg::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:EchoMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EchoMsg::CopyFrom(const EchoMsg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:EchoMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoMsg::IsInitialized() const {
  return true;
}

void EchoMsg::Swap(EchoMsg* other) {
  if (other == this) return;
  InternalSwap(other);
}
void EchoMsg::InternalSwap(EchoMsg* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  msg_.Swap(&other->msg_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::google::protobuf::Metadata EchoMsg::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_msg_2eproto);
  return ::file_level_metadata_msg_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::EchoMsg* Arena::CreateMaybeMessage< ::EchoMsg >(Arena* arena) {
  return Arena::CreateInternal< ::EchoMsg >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>