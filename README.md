# The Walker Game

A small first-person exploration game where player navigates through the area and discovers hidden objects.

## Game Overview

Main goal was to create a small game with two main mechanics:
- Exploration
- Object collection

Players will find themselves in abandoned area with a mysterious house and a garden.

## Player controls
  - WASD movement
  - Mouse-look camera controls
  - Interaction system for picking up items with popup hints


## Development

### 3D Modeling in Blender

| Stage 1 | Stage 2 | Stage 3 |
|---------|---------|---------|
| ![House model creation](Media/Pictures/blender_house_0.jpg) | ![Interior development](Media/Pictures/blender_house_1.jpg) | ![Final touches](Media/Pictures/blender_house_2.jpg) |
| House model creation | Interior development | Final touches |

### Area overview in Unreal Engine

| Stage 1 | Stage 2 | Stage 3 |
|---------|---------|---------|
| ![Abandoned garden](Media/Pictures/ue_scene_0.png) | ![House](Media/Pictures/ue_scene_1.png) | ![Collectables](Media/Pictures/ue_scene_2_items.png) |
| Abandoned garden | House | Collectables |

### Interior Development

| Stage 1 | Stage 2 | Stage 3 |
|---------|---------|---------|
| ![Interior View 1](Media/Pictures/ue_houseinterior_0.png) | ![Interior View 2](Media/Pictures/ue_houseinterior_1.png) | ![Interior View 3](Media/Pictures/ue_houseinterior_2.png) |
| Light placing | Intermediate result | Final interior |

### Gameplay Overview

![Gameplay Screenshot 1](Media/Pictures/ue_gameplay_0.png)
Popup hint that occurs when player comes closer to collectable.
Collectables are hightlighted with source of light.

![Gameplay Screenshot 2](Media/Pictures/ue_gameplay_1.png)
When all an item is being collected, it moves to the bedroom (quite mysteriously :))

## Gameplay video

https://github.com/user-attachments/assets/3e082019-74ab-4e61-9ab9-a694567e0210

## Lastly

The main goal was to implement minimal playable example with possible further refinement and optimization
