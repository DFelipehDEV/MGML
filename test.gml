/// PlayerActionLightspeed()

afterimageTime = 15;
if (distance_to_object(objRing) > 90 || !instance_exists(objRing) || ground) {
    PlayerActionSet(PlayerActionNormal);
    xSpeed /= 1.65;
    ySpeed /= 1.2;
}
else {
    ringNear = instance_nearest(x, y, objRing)
    ringDir = point_direction(x, y, ringNear.x, ringNear.y);
    xSpeed = lerp(xSpeed, lengthdir_x(12, ringDir), 0.4);
    ySpeed = lerp(ySpeed, lengthdir_y(12, ringDir), 0.4);
    animationAngle = point_direction(xprevious, yprevious, x, y)-90
}