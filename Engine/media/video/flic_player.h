//=============================================================================
//
// Adventure Game Studio (AGS)
//
// Copyright (C) 1999-2011 Chris Jones and 2011-2024 various contributors
// The full list of copyright holders can be found in the Copyright.txt
// file, which is part of this source code distribution.
//
// The AGS source code is provided under the Artistic License 2.0.
// A copy of this license can be found in the file License.txt and at
// https://opensource.org/license/artistic-2-0/
//
//=============================================================================
//
// FLIC video player implementation.
//
//=============================================================================
#ifndef __AGS_EE_MEDIA__FLICPLAYER_H
#define __AGS_EE_MEDIA__FLICPLAYER_H

#include "media/video/videoplayer.h"

namespace AGS
{
namespace Engine
{

class FlicPlayer : public VideoPlayer
{
public:
    FlicPlayer() = default;
    ~FlicPlayer();

    bool IsValid() override { return _pf != nullptr; }

private:
    Common::HError OpenImpl(std::unique_ptr<Common::Stream> data_stream,
        const String &name, int &flags, int target_depth) override;
    void CloseImpl() override;
    bool NextFrame() override;

    PACKFILE *_pf = nullptr;
    RGB _oldpal[256]{};
};

} // namespace Engine
} // namespace AGS

#endif // __AGS_EE_MEDIA__FLICPLAYER_H
