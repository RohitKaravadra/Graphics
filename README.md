# 🖼️ Rasterizer  
### _A Custom Real-Time 3D Rasterization Engine (C++ / DirectX11)_

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B17-blue?style=for-the-badge&logo=c%2B%2B">
  <img src="https://img.shields.io/badge/Renderer-Type%3A%20Rasterizer-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Platform-Windows-lightgrey?style=for-the-badge">
  <img src="https://img.shields.io/badge/University-Warwick%20WMG-orange?style=for-the-badge">
</p>

<p align="center">
  <img src="https://github.com/RohitKaravadra/Rasterizer/blob/main/Readme/Image1.png?raw=true" alt="Rasterizer Example" width="100%" style="border-radius:10px; object-fit:cover;">
</p>

---

## 📘 Overview

This project is a **custom 3D rasterizer** built from scratch in **C++** using **DirectX11**.  
It was developed for coursework at the **University of Warwick** under the guidance of **Prof. Thomas Bashford-Rogers**, exploring the fundamentals of **real-time rendering** and graphics pipeline construction.

The focus is on:
- 🧩 **Clean, modular architecture**  
- ⚡ **Real-time rendering techniques**  
- 🎮 **Interactive demos and animations**  

It serves as both a **learning tool** and a **foundation for more advanced real-time graphics experiments**.

---

## 🚀 Features Implemented

| Feature | Status | Notes |
|---------|--------|-------|
| **3D Transformations & Projections** | ✅ | World, View, Projection matrices |
| **Vertex & Skeletal Animations** | ✅ | Bone weights and skinning applied per vertex |
| **Flat Lighting** | ✅ | Basic directional lighting for surfaces |
| **Deferred Rendering Pipeline** | ✅ | Geometry & lighting passes implemented |
| **AABB Collision Detection** | ✅ | Axis-Aligned Bounding Box for scene objects |
| **Third-Person Character Controller** | ✅ | Camera & movement controls integrated |

---

## 🛠️ In Progress

| Feature | Status | Notes |
|---------|--------|-------|
| **Shadow Mapping** | 🌑 In Progress | Directional lights & dynamic shadows |
| **Advanced Lighting Models** | 🔴 Planned | PBR & multiple light types planned |
| **Post-Processing Effects** | 🔴 Planned | Bloom, motion blur, and tone mapping planned |

<p align="center">
  <img src="https://github.com/RohitKaravadra/Rasterizer/blob/main/Readme/Image2.png?raw=true" alt="Shadow Mapping Example" width="70%" style="border-radius:10px;">
</p>

---

## ⌨️ Controls

| Key | Action |
|-----|--------|
| **W/A/S/D** | Move character |
| **Mouse** | Camera rotation |
| **Space** | Jump |
| **Shift** | Run / Sprint |

---

## ⚒️ Command-Line / Config Options

This rasterizer is currently designed for **interactive builds** via Visual Studio.  
Future versions may include command-line switches for:
- Scene loading  
- Debug rendering modes  
- Frame capture / screenshots  

---

## 💬 Acknowledgements

> **Developed under:** Prof. Thomas Bashford-Rogers.  
> **Based on:** DirectX11 tutorials and custom engine architecture for learning purposes.

---

## 🎥 Demos

<p align="center">
  <img src="https://github.com/RohitKaravadra/Rasterizer/blob/main/Readme/GIF1.gif?raw=true" width="49%" />
  <img src="https://github.com/RohitKaravadra/Rasterizer/blob/main/Readme/GIF2.gif?raw=true" width="49%" />
</p>
