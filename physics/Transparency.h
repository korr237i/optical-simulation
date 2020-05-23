#ifndef OPTICAL_SIMULATION_TRANSPARENCY_H
#define OPTICAL_SIMULATION_TRANSPARENCY_H

#include <SFML/Graphics.hpp>
#include "parameters.h"

///
/// Class used to store 2D array of object transparency.
///
class Transparency : public QObject
{
Q_OBJECT
public:
    Transparency();
    Transparency(const Transparency& object);   /// construct object from given
    Transparency(ObjType objType, int XSize);           /// EDGE, GAP or CIRCLE
    Transparency(dataT2D& field, int XSize, int YSize); /// random field XSize*YSize
    virtual ~Transparency() {}

    void Init(const Transparency &object);
    void Update(int size);
    void CopyOpaqueFourier();
    void setRelativeOpaque(const Transparency *object = nullptr);
    void relativeOpaqueImage();
    void createPreview(sf::Vector2i position = {0, 0}, int pixelSize = PREVIEW_PIXEL_SIZE);   /// Called on update, but might be manually called for specific purposes
    void CreateFourierImage();
    void CreateInverseFourierImage();
    void ApplyFourierImage();
    void CreateImage(dataT z, dataT lambda, dataT scale);
    void FourierNormalize();

public slots:
    void UpdateSize(int size);
    void UpdateFourier();

public:
    double position;                /// Distance from light emitter
    ObjType type;
    dataT2D absoluteOpaque;         /// Characteristic of the object itself  1 - transparent 0 - not transparent
    dataT2D relativeOpaque;         /// Relative to falling light            1 - transparent 0 - not transparent
    dataT2Dc fourierImage;

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    /// Everything for preview
    sf::Image imagePreview;
    sf::Texture texturePreview;
    sf::Sprite spritePreview;
};

typedef std::vector<Transparency> ObjHolder;


#endif //OPTICAL_SIMULATION_TRANSPARENCY_H
