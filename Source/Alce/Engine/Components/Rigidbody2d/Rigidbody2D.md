# 🧩 Rigidbody2D

> <img src="https://box2d.org/images/logo.svg" style="width: 23px; position: relative; top: 1px"> [Built using the Box2d library.](https://github.com/erincatto/box2d)

The ```Rigidbody2D``` component provides a 2D physics body for a GameObject, enabling interaction with the physics simulation.
It integrates the object into the __Box2D__ world and controls physical properties such as density, friction, restitution, damping, and velocity.

A ```Rigidbody2D``` can be defined as ```dynamic```, ```static```, or ```kinematic```, making it suitable for a wide range of use cases: characters, platforms, projectiles, sensors, or static colliders.
Forces, impulses, and torques can be applied at runtime, and the component automatically keeps the associated GameObject’s transform in sync with the physics world.

# Behaviour

The ```Rigidbody2D``` component integrates a GameObject into the 2D physics simulation. It automatically synchronizes the GameObject’s transform with the physics body, ensuring that position and rotation reflect the physics world. Forces, impulses, and torques applied through the component directly affect motion, velocity, and rotation. Changes to physical properties such as density, friction, restitution, or damping immediately influence how the body interacts with collisions and other ```Rigidbody2D``` instances. The body type (dynamic, static, kinematic) determines whether it responds to physics forces, is immovable, or can be controlled manually while still affecting other bodies.

# Fields

* ```float density```: Mass density of the body. Default is 10.0.

* ```float friction```: Friction coefficient of the body. Default is 1.0.

* ```float restitution```: Bounciness of the body. Default is 0.0.

* ```float	restitutionThreshold```: Minimum velocity required for restitution to take effect. Default is 0.0.

* ```BodyType bodyType```: Type of body (```static_body```, ```dynamic_body```, ```kinematic_body```, or ```none_body```).

* ```float radius```: Radius of the body (if applicable).

* ```b2Body* body```: Pointer to the __Box2D__ body. Null if body hasn’t been created yet.

* ```b2Fixture* fixture```: Pointer to the __Box2D__ fixture associated with the body.

* ```ContactListenerPtr contactListener```: Optional contact listener for collision callbacks.

* ```B2WorldPtr world```: Reference to the physics world the body belongs to.

* ```ShapePtr shape```: Shape used to create the body.

* ```Vector2 shapePos```: Local position of the shape relative to the body.

## Constructors

### Default Constructor

```cpp
Rigidbody2D()
```

Creates a new ```Rigidbody2D``` instance. No body is created until CreateBody is called.

## Destructor

```cpp
~Rigidbody2D()
```

Destroys the underlying physics body if it exists.

# Body Management

## CreateBody
```cpp
void CreateBody(ShapePtr shape, BodyType bodyType = BodyType::dynamic_body, bool fixedRotation = false, MaskType maskType = MaskType::mask_1)
```

Creates and attaches a physics body to the component using the provided shape and parameters.

Parameters:

* ```shape```: Shape of the body (rectangle, circle, polygon).

* ```bodyType```: The type of body (dynamic, static, kinematic).

* ```fixedRotation```: Whether the body should ignore rotation.

* ```maskType```: Collision mask category.

## DestroyBody
```cpp
void DestroyBody()
```

Destroys the currently attached physics body, if any.

# Physical Properties

## Density
```cpp
float GetDensity()
void SetDensity(float density)
```

Gets or sets the density of the body. Updating density recalculates the mass.

## Friction
```cpp
float GetFriction()
void SetFriction(float friction)
```

Gets or sets the surface friction coefficient.

## Restitution
```cpp
float GetRestitution()
void SetRestitution(float restitution)
```

Gets or sets the restitution (bounciness).

## RestitutionThreshold
```cpp
float GetRestitutionThreshold()
void SetRestitutionThreshold(float restitutionThreshold)
```

Gets or sets the minimum relative speed at which restitution is applied.

## Inertia
```cpp
float GetInertia()
```

Returns the rotational inertia of the body.

## GravityScale
```cpp
float GetGravityScale()
```

Returns the gravity scaling factor applied to this body.

# Forces & Motion

## ApplyForce
```cpp
void ApplyForce(Vector2 force, bool wake = true)
```

Applies a continuous force to the body’s center.

## ApplyLinearForce
```cpp
void ApplyLinearForce(Vector2 force, bool wake = true)
```

Applies an instantaneous linear impulse to the body’s center.

## ApplyAngularImpulse
```cpp
void ApplyAngularImpulse(float impulse)
```

Applies an angular impulse, instantly changing angular velocity.

## ApplyTorque
```cpp
void ApplyTorque(float torque, bool wake = true)
```

Applies continuous torque to the body.

## LinearVelocity
```cpp
void SetLinearVelocity(Vector2 velocity)
Vector2 GetLinearVelocity()
```

Sets or gets the linear velocity.

## SetVerticalVelocity
```cpp
void SetVerticalVelocity(float vy)
```

Sets the vertical velocity, keeping horizontal unchanged.

## SetHorizontalVelocity
```cpp
void SetHorizontalVelocity(float vx)
```

Sets the horizontal velocity, keeping vertical unchanged.

## SetAngularVelocity
```cpp
void SetAngularVelocity(float va)
```

Sets the angular velocity.

## SetAngularDamping
```cpp
void SetAngularDamping(float ad)
```

Sets the angular damping factor (slows down rotation over time).

## SetLinearDamping
```cpp
void SetLinearDamping(float ld)
```

Sets the linear damping factor (slows down movement over time).

# Transform & Orientation

## Angle
```cpp
float GetAngle()
void SetAngle(float angle)
```

Gets or sets the body’s rotation angle in radians.

## GetPosition
```cpp
Vector2 GetPosition()
```

Returns the current world position of the body.

## SetPosition
```cpp
void SetPosition(Vector2 position, bool awake = true)
void SetPosition(float x, float y, bool awake = true)
```

Moves the body to the given position.

## SetRotation
```cpp
void SetRotation(float angle, bool awake = true)
```

Rotates the body to the specified angle.

## SetFixedRotation
```cpp
void SetFixedRotation(bool flag)
```

Enables or disables rotation for the body.

# Body Definition

## BodyType
```cpp
BodyType GetBodyType()
void SetBodyType(BodyType bodyType)
```

Gets or sets the type of the body (dynamic, static, kinematic).

## GetShapeType
```cpp
ShapeType GetShapeType()
```

Returns the type of the shape used by the body.

# Tagging

## Tag
```cpp
void SetTag(String tag)
String GetTag()
```

Assigns or retrieves a string tag for the body, useful for categorization or identification.