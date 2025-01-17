//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft Corporation and contributors. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

#pragma once

namespace Wasm
{

    class WasmElementSegment
    {
    public:
        WasmElementSegment(ArenaAllocator * alloc, const UINT32 index, const WasmNode initExpr, const UINT32 numElem);
        void AddElement(const UINT32 funcIndex, const WasmModule& module);
        UINT32 GetElement(const UINT32 tableIndex) const;
        UINT32 GetNumElements() const { return m_numElem; }
        void ResolveOffsets(const WasmModule& module);

    private:
        ArenaAllocator* m_alloc;
        UINT32 m_index;
        const WasmNode m_offsetExpr;
        UINT32 m_numElem;
        UINT32 m_offset;
        UINT32 m_limit;
        UINT32 m_elemIdx;
        bool m_isOffsetResolved;
        UINT32* m_elems;

        void Init(const WasmModule& module);
        bool IsOffsetResolved() const;
    };
} // Namespace Wasm
