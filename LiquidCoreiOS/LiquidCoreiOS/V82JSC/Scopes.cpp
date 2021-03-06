//
//  Scopes.cpp
//  LiquidCore
//
//  Created by Eric Lange on 1/28/18.
//  Copyright © 2018 LiquidPlayer. All rights reserved.
//

#include <v8.h>

using namespace v8;

std::vector<internal::Object*> m_handles;

HandleScope::HandleScope(Isolate* isolate)
{
    
}

HandleScope::~HandleScope()
{
    
}

int HandleScope::NumberOfHandles(Isolate* isolate)
{
    return (int) m_handles.size();
}

internal::Object** HandleScope::CreateHandle(internal::Isolate* isolate,
                                       internal::Object* value)
{
    m_handles.push_back(value);
    //return &(*m_handles.end());
    return reinterpret_cast<internal::Object**>(value);
}

internal::Object** HandleScope::CreateHandle(internal::HeapObject* heap_object,
                                       internal::Object* value)
{
    m_handles.push_back(value);
    return &* (m_handles.end());
}

EscapableHandleScope::EscapableHandleScope(Isolate* isolate)
{
    
}

internal::Object** EscapableHandleScope::Escape(internal::Object** escape_value)
{
    return nullptr;
}

SealHandleScope::~SealHandleScope()
{
    
}

SealHandleScope::SealHandleScope(Isolate* isolate) : isolate_(nullptr)
{
    
}

MicrotasksScope::MicrotasksScope(Isolate* isolate, Type type) : isolate_(nullptr)
{
    
}
MicrotasksScope::~MicrotasksScope()
{
    
}

/**
 * Runs microtasks if no kRunMicrotasks scope is currently active.
 */
void MicrotasksScope::PerformCheckpoint(Isolate* isolate)
{
    
}

/**
 * Returns current depth of nested kRunMicrotasks scopes.
 */
int MicrotasksScope::GetCurrentDepth(Isolate* isolate)
{
    return 0;
}

/**
 * Returns true while microtasks are being executed.
 */
bool MicrotasksScope::IsRunningMicrotasks(Isolate* isolate)
{
    return false;
}

