#ifndef CABLE_H_
#define CABLE_H_

#include "appliance.h"
#include "entity.h"
#include "raylib.h"
#include <stddef.h>

typedef struct {
    Vector2 position;
    size_t spriteID;
    bool visible;
} Anchor;

struct Cable{
    float maxLength;
    size_t nMaxAnchors;
    size_t nAnchors;
    size_t nConnectedAppliances;
    Anchor* anchors;
};

typedef enum {
ANCHOR_SUCCESS,
ANCHOR_NOT_ENOUGH_ANCHORS,
ANCHOR_NOT_ENOUGH_LENGTH,
ANCHOR_OBSTRUDED_PATH,
} PLACE_ANCHOR_RESULT;

Cable createCable(Vector2 initialAnchor, size_t maxAnchors, float maxLength);

Anchor* cableGetLastAnchor(Cable* cable);

void destroyCable(Cable* cable);

float computeCableLength(Cable* cable);

PLACE_ANCHOR_RESULT tryCreateAnchor(Cable* cable, GameColliderList* c_list, ApplianceList* a_list,  Vector2 position);

void drawCable(Cable* cable, Player* player, GameColliderList* c_list);

bool tryRemoveLastAnchor(Cable* cable, ApplianceList* a_list, Vector2 position);

#endif // CABLE_H_
