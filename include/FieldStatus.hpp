#pragma once

enum class FieldStatus
{
    // order of enum values is important. It is ordered according to tiles graphic
    FREE,
    SHIP,
    SHOT,
    MISSED,
    SHIP_SURROUNDING,
    OUT_OF_BOUNDS
};