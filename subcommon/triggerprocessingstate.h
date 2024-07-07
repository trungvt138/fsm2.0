//
// Created by trung on 31/05/2024.
//

#ifndef TRIGGERPROCESSINGSTATE_H
#define TRIGGERPROCESSINGSTATE_H

enum class TriggerProcessingState {
    consumed,
    pending,
    endstatereached,
    ws_transfered_reached,
    ws_sorted_reached,
    both_slide_full
};

#endif //TRIGGERPROCESSINGSTATE_H
